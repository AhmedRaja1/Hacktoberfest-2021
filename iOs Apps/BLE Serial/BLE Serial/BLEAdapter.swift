//
//  BLEAdapter.swift
//  BLE Serial
//
//  Created by Muhammad Hammad on 19/10/2021.
//

import UIKit
import CoreBluetooth

// MARK: - Protocols
protocol ScanResultsConsumer {
    func onDeviceDiscovered(_ peripheral: CBPeripheral)
}

protocol BluetoothOperationsConsumer {
    func onConnected()
    func onFailedToConnect(_ error: Error?)
    func onDisconnected()
    func onServicesDiscovered()
    func onRXDiscovered()
    func onTXDiscovered()
    func receive(_ receivedString: String)
}

class BLEAdapter: NSObject, CBCentralManagerDelegate, CBPeripheralDelegate {
    var centralManager: CBCentralManager?
    var selectedPeripheral: CBPeripheral?
    var peripherals: NSMutableArray = []
    var poweredOn : Bool?
    var scanning: Bool?
    var connected: Bool?
    
    static let sharedInstance = BLEAdapter()
    
    var scanResultsConsumer: ScanResultsConsumer?
    var bluetoothOperationsConsumer: BluetoothOperationsConsumer?
    
    let UART_SERVICE_UUID = "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
    let RX_CHARACTERISTIC_UUID = "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
    let TX_CHARACTERISTIC_UUID = "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"
    
    var rxCharacteristic: CBCharacteristic?
    var txCharacteristic: CBCharacteristic?
    
    // MARK: - CBCentralManagerDelegate Functions
    func centralManager(_ central: CBCentralManager, willRestoreState dict: [String : Any]) {
        self.peripherals = dict[CBCentralManagerRestoredStatePeripheralsKey] as! NSMutableArray;
    }
    
    func centralManagerDidUpdateState(_ central: CBCentralManager) {
        if(central.state == CBManagerState.poweredOn) {
            poweredOn = true
            return
        }
        
        if(central.state == CBManagerState.poweredOff) {
            poweredOn = false
            return
        }
    }
    
    func centralManager(_ central: CBCentralManager, didConnect peripheral: CBPeripheral) {
        connected = true
        bluetoothOperationsConsumer?.onConnected()
    }
    
    func centralManager(_ central: CBCentralManager, didFailToConnect peripheral: CBPeripheral, error: Error?) {
        bluetoothOperationsConsumer?.onFailedToConnect(error)
    }
    
    func centralManager(_ central: CBCentralManager, didDisconnectPeripheral peripheral: CBPeripheral, error: Error?) {
        connected = false
        bluetoothOperationsConsumer?.onDisconnected()
    }
    
    func centralManager(_ central: CBCentralManager, didDiscover peripheral: CBPeripheral, advertisementData: [String : Any], rssi RSSI: NSNumber) {
        var i = 0
        
        while i < self.peripherals.count {
            let p = self.peripherals.object(at: i)
            if((p as AnyObject).identifier == peripheral.identifier) {
                self.peripherals.replaceObject(at: i, with: peripheral)
                return
            }
            i = i + 1
        }
        
        // did not find device in our array so it must be a new device
        self.peripherals.add(peripheral)
        scanResultsConsumer?.onDeviceDiscovered(peripheral)
    }
    
    // MARK: - CBPeripheralDelegate Functions
    func peripheral(_ peripheral: CBPeripheral, didDiscoverServices error: Error?) {
        print("didDiscoverServices")
        bluetoothOperationsConsumer?.onServicesDiscovered()
    }
    
    func peripheral(_ peripheral: CBPeripheral, didDiscoverCharacteristicsFor service: CBService, error: Error?) {
        let UARTserviceUUID = CBUUID(string: UART_SERVICE_UUID)
        let rxUUID = CBUUID(string: RX_CHARACTERISTIC_UUID)
        let txUUID = CBUUID(string: TX_CHARACTERISTIC_UUID)
        
        if let characteristics = service.characteristics {
            for characteristic in characteristics {
                print(characteristic.uuid)
                
                if service.uuid == UARTserviceUUID {
                    if (characteristic.uuid == rxUUID) {
                        rxCharacteristic = characteristic
                        bluetoothOperationsConsumer?.onRXDiscovered()
                        
                    } else if (characteristic.uuid == txUUID) {
                        txCharacteristic = characteristic
                        bluetoothOperationsConsumer?.onTXDiscovered()
                    }
                }
            }
        
        }
    }
    
    func peripheral(_ peripheral: CBPeripheral, didUpdateValueFor characteristic: CBCharacteristic, error: Error?){
        print("didUpdateValueFor characteristic: service=\(characteristic.service!.uuid.uuidString) characteristic=\(characteristic.uuid.uuidString)")
        
        if characteristic.service!.uuid == CBUUID(string: UART_SERVICE_UUID) && characteristic.uuid == CBUUID(string: TX_CHARACTERISTIC_UUID) {
            if let data = characteristic.value {
                let receivedString = String(decoding: data, as: UTF8.self)
                bluetoothOperationsConsumer?.receive(receivedString)
            } else {
                print("ERROR: NO DATA from characteristic")
            }
        }
    }
    
    // MARK: - Adapter Functions
    func initBluetooth(_ deviceList : DeviceListTableViewController) {
        poweredOn = false
        scanning = false
        connected = false
        self.centralManager = CBCentralManager(delegate: self, queue: nil, options: [CBCentralManagerOptionRestoreIdentifierKey:"hammad"])
        self.scanResultsConsumer = deviceList
    }
    
    func findDevices(_ timeout: Int, _ consumer: ScanResultsConsumer) -> Int {
        if(self.centralManager?.state != CBManagerState.poweredOn) {
            print("Bluetooth is not powered on");
            return -1
        }
        
        peripherals.removeAllObjects()
        Timer.scheduledTimer(timeInterval: Double(timeout), target: self, selector: #selector(BLEAdapter.stopScanning(_:)), userInfo: nil, repeats: false)
        scanning = true
        self.centralManager?.scanForPeripherals(withServices: nil, options: nil)
        return 0
    }
    
    @objc
    func stopScanning(_ timer: Timer) {
        if (scanning == true) {
            self.centralManager?.stopScan()
            scanning = false
        }
    }
    
    func stopScanning() {
        if (scanning == true) {
            self.centralManager?.stopScan()
            scanning = false
        }
    }
    
    func printKnownPeripherals() {
        print("List of currently known peripherals : ");
        
        let count = self.peripherals.count
        
        if (count > 0) {
            for i in 0 ... count - 1 {
                let p = self.peripherals.object(at: i) as! CBPeripheral
                self.printDeviceDetails(p)
            }
        }
    }
    
    func printDeviceDetails(_ peripheral: CBPeripheral) {
        print("Peripheral Info :");
        print("Name : \(peripheral.name ?? "No name")")
        print("ID : \(peripheral.identifier)")
    }
    
    func centralManagerStateToString(_ state: CBManagerState) -> [CChar]? {
        var returnVal = "Unknown state"
        
        if (state == CBManagerState.unknown) {
            returnVal = "State unknown (CBManagerStateUnknown)"
            
        } else if (state == CBManagerState.resetting) {
            returnVal = "State resetting (CBManagerStateUnknown)"
            
        } else if (state == CBManagerState.unsupported) {
            returnVal = "State BLE unsupported (CBCentralManagerStateResetting)"
            
        } else if (state == CBManagerState.unauthorized) {
            returnVal = "State unauthorized (CBCentralManagerStateUnauthorized)"
            
        } else if (state == CBManagerState.poweredOff) {
            returnVal = "State BLE powered off (CBCentralManagerStatePoweredOff)"
            
        } else if (state == CBManagerState.poweredOn) {
            returnVal = "State powered up and ready (CBCentralManagerStatePoweredOn)"
            
        } else {
            returnVal = "State unknown"
        }
        
        return (returnVal.cString(using: String.Encoding.utf8))
    }
    
    func connect(_ resultConsumer: BluetoothOperationsConsumer) {
        if (selectedPeripheral != nil) {
            selectedPeripheral?.delegate = self
            bluetoothOperationsConsumer = resultConsumer
            centralManager?.connect(selectedPeripheral!, options: nil)
        }
    }
    
    func disconnect(_ resultConsumer: BluetoothOperationsConsumer) {
        if (selectedPeripheral != nil) {
            bluetoothOperationsConsumer = resultConsumer
            centralManager?.cancelPeripheralConnection(selectedPeripheral!)
        }
    }
    
    func discoverServices() {
        self.selectedPeripheral?.discoverServices(nil)
    }
    
    func discoverCharacteristics() {
        if let services = selectedPeripheral?.services {
            for service in services {
                if (service.uuid == CBUUID(string: UART_SERVICE_UUID)) {
                    selectedPeripheral?.discoverCharacteristics(nil, for: service)
                }
            }
        }
    }
    
    func send(text: String) {
        let textStringUTF8 = Data(text.utf8)
        selectedPeripheral?.writeValue(textStringUTF8, for: rxCharacteristic!, type: .withResponse)
    }
    
    func setTXCharacteristicNotifications(state: Bool) {
        selectedPeripheral?.setNotifyValue(state, for: txCharacteristic!)
    }
}

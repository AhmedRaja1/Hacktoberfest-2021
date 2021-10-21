//
//  DeviceListTableViewController.swift
//  BLE Serial
//
//  Created by Muhammad Hammad on 19/10/2021.
//

import UIKit
import CoreBluetooth

class DeviceListTableViewController: UITableViewController, ScanResultsConsumer {
    var adapter: BLEAdapter!
    var utils: Utils!
    var devices :NSMutableArray = []
    var scanTimer = Timer()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        Thread.sleep(forTimeInterval: 0.75)   //To make the launch screen stay for half seconds
        
        adapter = BLEAdapter.sharedInstance
        adapter.initBluetooth(self)
        
        utils = Utils.sharedInstance
    }

    // MARK: - Table view data source
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return devices.count
    }

    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "DeviceTableViewCell", for: indexPath) as! DeviceTableViewCell
        let device = devices.object(at: indexPath.row) as! Device
        cell.deviceName.text = device.deviceName
        cell.deviceAddress.text = device.deviceAddress.uuidString
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        performSegue(withIdentifier: "showDeviceControlSegue", sender: self)
    }
    
    // MARK: - Navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if (adapter.scanning == true) {
            print("stopping scanning")
            adapter.stopScanning()
            scanTimer.invalidate()
        }
        
        if let index = tableView.indexPathForSelectedRow?.row {
            let selectedDevice = devices[index] as! Device
            adapter.selectedPeripheral = selectedDevice.peripheral
        }
    }
    
    
    // MARK: - Delegate Functions
    func onDeviceDiscovered(_ peripheral: CBPeripheral) {
        if let discoveredDeviceName = peripheral.name {
            let device = Device(peripheral: peripheral, deviceAddress: peripheral.identifier, deviceName: discoveredDeviceName)
            devices.insert(device, at: 0)
            
        } else {
            let device = Device(peripheral: peripheral, deviceAddress: peripheral.identifier, deviceName: "no name")
            devices.insert(device, at: 0)
        }
        
        let indexPath = IndexPath(row: 0, section: 0)
        var indexesPath:[IndexPath] = [IndexPath]()
        indexesPath.append(indexPath)
        self.tableView.insertRows(at: indexesPath, with: UITableView.RowAnimation.automatic)
    }
    
    // MARK: - Button Presses
    
    @IBAction func onScan(_ sender: UIBarButtonItem) {
        startScan()
    }
    
    func startScan() {
        if (adapter.scanning == true) {
            print("Already scanning - ignoring")
            return
        }
        
        if (adapter.poweredOn == false) {
            utils.showAlert(message: "Turn on Bluetooth to start scanning!", view: self)
            return
        }
        
        if (adapter.scanning == false) {
            adapter.scanning = true
            
            print("Will start scanning shortly")
            
            devices.removeAllObjects()
            self.tableView.reloadData()
            
            // scan for 10 seconds
            let rc = adapter.findDevices(10, self) //Scan for 10 seconds
            
            if (rc == -1) {
                utils.showAlert(message: "Turn on Bluetooth to start scanning!", view: self)
                
            } else {
                print("Setting up timer for when scanning is finished")
                
                scanTimer = Timer.scheduledTimer(
                    timeInterval: 10.0,
                    target: self,
                    selector: #selector(DeviceListTableViewController.scanningFinished(_:)),
                    userInfo: nil,
                    repeats: false)
            }
        }
    }
    
    @objc func scanningFinished(_ timer: Timer) {
        print("Finished scanning")
        adapter.scanning = false
        
        if (adapter.peripherals.count > 0) {
            utils.showAlert(message: "Finished Scanning!", view: self)
        } else {
            utils.showAlert(message: "No Devices were Found!", view: self)
        }
    }
}

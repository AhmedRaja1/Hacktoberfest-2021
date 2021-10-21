//
//  DeviceViewController.swift
//  BLE Serial
//
//  Created by Muhammad Hammad on 19/10/2021.
//

import UIKit

class DeviceViewController: UIViewController, BluetoothOperationsConsumer {
    var adapter: BLEAdapter!
    var utils: Utils!
    
    @IBOutlet weak var connectButton: UIButton!
    @IBOutlet weak var deviceDetailsLabel: UILabel!
    @IBOutlet weak var statusLabel: UILabel!
    
    @IBOutlet weak var textToSendTextField: UITextField!
    @IBOutlet weak var receivedTextLabel: UILabel!
    @IBOutlet weak var sendButton: UIButton!
    
    // MARK: View will appear
    override func viewDidLoad() {
        super.viewDidLoad()
        
        adapter = BLEAdapter.sharedInstance
        utils = Utils.sharedInstance
        
        deviceDetailsLabel.text = "Name: \(adapter.selectedPeripheral!.name ?? "No Name"), UUID:\( adapter.selectedPeripheral!.identifier.uuidString)"
        
        textToSendTextField.isEnabled = false
        receivedTextLabel.isEnabled = false
        sendButton.isEnabled = false
    }
    
    // MARK: View will disappear
    override func viewWillDisappear(_ animated : Bool) {
        super.viewWillDisappear(animated)
        
        if self.isMovingFromParent {
            if (adapter.connected == true) {
                print("Disconnecting!")
                adapter.disconnect(self)
            }
        }
    }
    
    @objc
    func dismissKeyboard() {
        view.endEditing(true)
    }
    
    // MARK: - Button Presses
    @IBAction func connectButtonPressed(_ sender: Any) {
        if (adapter.connected == false) {
            adapter.connect(self)
        } else {
            adapter.disconnect(self)
        }
    }
    
    @IBAction func sendButtonPressed(_ sender: Any) {
        if (adapter.connected == true) {
            let textToSend: String = textToSendTextField.text!.trimString()
            
            if (textToSend != "") {
                adapter.send(text: textToSend)
            } else {
                utils.showAlert(message: "Type something to send!!", view: self)
            }
        } else {
            utils.showAlert(message: "Connect to a Device first!", view: self)
        }
    }
    
    @IBAction func donePressed(_ sender: Any) {
        self.dismissKeyboard()
    }
    @IBAction func infoButtonPressed(_ sender: Any) {
        let alert = UIAlertController(title: "Info", message: "This app uses the Nordic UART Service to connect to peripherals and exchange data. The esp32 Arduino Example to work with this app can be found at \"https://github.com/hammad1201/NordicUARTExampleEsp32\"", preferredStyle: .alert)
        
        alert.addAction(UIAlertAction(title: "Visit Link", style: .default, handler: {action in
            UIApplication.shared.open(URL(string: "https://github.com/hammad1201/NordicUARTExampleEsp32")!)
        }))
        
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))

        self.present(alert, animated: true, completion: nil)
    }
    
    // MARK: - Delegate Functions
    func onConnected() {
        print("onConnected")
        connectButton.backgroundColor = UIColor.systemRed
        connectButton.setTitle("Disconnect from Device", for: .normal)
        
        statusLabel.text = "Connected to Device!"
        statusLabel.textColor = UIColor.systemGreen
        
        textToSendTextField.isEnabled = true
        receivedTextLabel.isEnabled = true
        sendButton.isEnabled = true
        
        //Start Service Discovey
        adapter.discoverServices()
    }
    
    func onFailedToConnect(_ error: Error?) {
        print("onFailedToConnect")
        
        connectButton.backgroundColor = UIColor.systemGreen
        connectButton.setTitle("Connect to Device", for: .normal)
        
        statusLabel.text = "Failed to Connect!"
        statusLabel.textColor = UIColor.systemOrange
        
        textToSendTextField.isEnabled = false
        receivedTextLabel.isEnabled = false
        sendButton.isEnabled = false
        
        receivedTextLabel.text = "..............."
        utils.showAlert(message: "Failed to connect!", view: self)
    }
    
    func onDisconnected() {
        print("onDisconnected")
        
        connectButton.backgroundColor = UIColor.systemGreen
        connectButton.setTitle("Connect to Device", for: .normal)
        
        statusLabel.text = "Disconnected from Device!"
        statusLabel.textColor = UIColor.systemOrange
        
        textToSendTextField.isEnabled = false
        receivedTextLabel.isEnabled = false
        sendButton.isEnabled = false
        
        receivedTextLabel.text = "..............."
    }
    
    func onServicesDiscovered() {
        print("onServicesDiscovered")
        adapter.discoverCharacteristics()
    }
    
    func onRXDiscovered() {
        print("onRXCharacteristicDiscovered")
    }
    
    func onTXDiscovered() {
        print("onTXCharacteristicDiscovered")
        adapter.setTXCharacteristicNotifications(state: true)
    }
    
    func receive(_ receivedString: String) {
        receivedTextLabel.text = receivedString
        print(receivedString)
    }
}

extension String {
    func trimString() -> String {
        return self.trimmingCharacters(in: NSCharacterSet.whitespaces)
    }
}

//
//  Utils.swift
//  BLE Serial
//
//  Created by Muhammad Hammad on 19/10/2021.
//

import UIKit

class Utils {
    static let sharedInstance = Utils()
    
    // MARK: Show Alert Function
    func showAlert(message:String, view: UIViewController) {
        let alertDisapperTimeInSeconds = 2.0
        
        let alert = UIAlertController(title: nil, message: message, preferredStyle: .actionSheet)
        view.present(alert, animated: true)
        
        DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + alertDisapperTimeInSeconds) {
          alert.dismiss(animated: true)
        }
    }
}

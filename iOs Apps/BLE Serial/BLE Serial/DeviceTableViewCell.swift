//
//  DeviceTableViewCell.swift
//  BLE Serial
//
//  Created by Muhammad Hammad on 19/10/2021.
//

import UIKit

class DeviceTableViewCell: UITableViewCell {
    @IBOutlet weak var deviceName: UILabel!
    @IBOutlet weak var deviceAddress: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}

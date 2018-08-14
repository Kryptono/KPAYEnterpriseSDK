//
//  ViewController.swift
//  KPSSampleSwift
//
//  Copyright © 2018 Kryptono Exchange. All rights reserved.
//

import UIKit
import KryptonoPaymentSDK

class ViewController: UIViewController, KPFrameworkProtocol {
    let lbIntroduce = UILabel()
    let lbResult = UILabel()

    let btnLanguage = UIButton(type: .roundedRect)
    let btnOpenKryptono = UIButton(type: .custom)
    let btnOpenKryptono1 = UIButton(type: .custom)

    var languages : [KPFSupportedLocalization] = [kPFSL_English,
                                                  kPFSL_ChineseSimplified]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = .white
        
        // Do any additional setup after loading the view, typically from a nib.
        self.lbIntroduce.backgroundColor = .clear
        self.lbIntroduce.text = "Third party App is written in Swift"
        self.lbIntroduce.textColor = .black
        self.lbIntroduce.textAlignment = .center
        self.lbIntroduce.font = UIFont.boldSystemFont(ofSize: 16)
        self.lbIntroduce.numberOfLines = 5
        self.lbIntroduce.frame = CGRect(x: 10, y: self.view.height/2 - 200, width: self.view.width - 10*2, height: 50)
        self.view.addSubview(self.lbIntroduce)
        
        var y = self.lbIntroduce.frame.origin.y + self.lbIntroduce.frame.size.height + 20
        self.lbResult.backgroundColor = .clear
        self.lbResult.text = "PaymentID : --/--"
        self.lbResult.textColor = .black
        self.lbResult.textAlignment = .center
        self.lbResult.font = UIFont.boldSystemFont(ofSize: 16)
        self.lbResult.numberOfLines = 0
        self.lbResult.frame = CGRect(x: 10, y: y, width: self.view.width - 10*2, height: 100)
        self.view.addSubview(self.lbResult)
        
        y = self.lbResult.frame.origin.y + self.lbResult.frame.size.height + 30
        self.btnLanguage.backgroundColor = UIColor.white
        self.btnLanguage.layer.borderColor = UIColor.black.cgColor
        self.btnLanguage.layer.borderWidth = 0.5
        self.btnLanguage.layer.cornerRadius = 5.0
        self.btnLanguage.layer.masksToBounds = true
        self.btnLanguage.setTitle("Change SDK Language", for: .normal)
        self.btnLanguage.setTitleColor(.black, for: .normal)
        self.btnLanguage.addTarget(self, action: #selector(changeLanguage(sender:)), for: .touchUpInside)
        self.btnLanguage.frame = CGRect(x: self.view.frame.size.width/2 - 300/2, y: self.view.frame.size.height/2 + 60, width: 300, height: 50)
        self.view.addSubview(self.btnLanguage)
        
        y = self.btnLanguage.frame.origin.y + self.btnLanguage.frame.size.height + 40
        self.btnOpenKryptono.backgroundColor = UIColor.white
        self.btnOpenKryptono.layer.borderColor = UIColor.black.cgColor
        self.btnOpenKryptono.layer.borderWidth = 0.5
        self.btnOpenKryptono.layer.cornerRadius = 5.0
        self.btnOpenKryptono.layer.masksToBounds = true
        self.btnOpenKryptono.setTitle("OPEN SDK", for: .normal)
        self.btnOpenKryptono.setTitleColor(.black, for: .normal)
        self.btnOpenKryptono.addTarget(self, action: #selector(btnOpenKryptono_tap), for: .touchUpInside)
        self.btnOpenKryptono.frame = CGRect(x: self.view.width/2 - 80, y: y, width: 160, height: 50)
        self.view.addSubview(self.btnOpenKryptono)
        
        y = self.btnOpenKryptono.frame.origin.y + self.btnOpenKryptono.frame.size.height + 20
        self.btnOpenKryptono1.backgroundColor = UIColor.white
        self.btnOpenKryptono1.layer.borderColor = UIColor.black.cgColor
        self.btnOpenKryptono1.layer.borderWidth = 0.5
        self.btnOpenKryptono1.layer.cornerRadius = 5.0
        self.btnOpenKryptono1.layer.masksToBounds = true
        self.btnOpenKryptono1.setTitle("OPEN SDK WITH REQUESTED AMOUNT", for: .normal)
        self.btnOpenKryptono1.titleLabel?.font = UIFont.systemFont(ofSize: 15)
        self.btnOpenKryptono1.setTitleColor(.black, for: .normal)
        self.btnOpenKryptono1.addTarget(self, action: #selector(btnOpenKryptono1_tap), for: .touchUpInside)
        self.btnOpenKryptono1.frame = CGRect(x: self.view.width/2 - 300/2, y: y, width: 300, height: 50)
        self.view.addSubview(self.btnOpenKryptono1)
    }
    
    deinit {
        NSLog("App view controller dismissed")
    }
    
    @objc func btnOpenKryptono_tap() {
        KPFramework.launch(from: self,
                           userIdentity: "123456789",
                           delegate: self)
    }
    
    @objc func btnOpenKryptono1_tap() {
        let amountView = AmountView(frame: CGRect(x: 0, y: 0, width: self.view.frame.size.width, height: self.view.frame.size.height))
        amountView.openBlock = {(amount) in
            if amount <= 0 {
                self.showAlert(message: "Please enter a positive amount.")
                return
            }
            
            KPFramework.launch(from: self,
                               userIdentity: "1234556",
                               delegate: self,
                               yourCryptoRequestedAmount: amount)
        }
        
        self.view.addSubview(amountView)
    }
    
    private func showAlert(message : String) {
        let alert = UIAlertController(title: "ERROR", message: message, preferredStyle: .alert)
        let action = UIAlertAction(title: "Close", style: .cancel, handler: nil)
        alert.addAction(action)
        
        self.present(alert, animated: true, completion: nil)
    }
    
    @objc func changeLanguage(sender : Any) {
        let alertController = UIAlertController(title: "Language",
                                                message: "Please select one of following languages for SDK",
                                                preferredStyle: .actionSheet)
        for lang in self.languages {
            var langString : String = ""
            if lang == kPFSL_English {
                langString = "English"
            } else if lang == kPFSL_ChineseSimplified {
                langString = "Simplified Chinese"
            }
            let action = UIAlertAction(title: langString, style: .default, handler: {(a) in
                let _ = KPFramework.setDesiredLanguage(lang)
                self.btnLanguage.setTitle("Language for SDK: \(langString)", for: .normal)
            })
            alertController.addAction(action)
        }
        
        let cancel = UIAlertAction(title: "Cancel", style: .cancel, handler: {(a) in
            
        })
        alertController.addAction(cancel)
        
        self.present(alertController, animated: true, completion: nil)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func kpFramework(_ kpframework: KPFramework!, didReceivePayment paymentId: String!, error: KPFError) {
        var msg = ""
        
        switch error {
        case KPFError_Framework_Not_Configured:
            NSLog("KPFramework Error: ClientKey or ChecksumKey or UserId is not configured. Please pass ClientKey and ChecksumKey and UserId to method KPFramework.configure(withClientKey:, checksumKey:, userId:)")
            
            msg = "ClientKey or ChecksumKey or UserId is not configured. Check Log Console for more detail."
            
            break
        case KPFError_InvalidClientKey:
            NSLog("KPFramework Error: ClientKey is invalid. Please contact us for support")
            
            msg = "ClientKey is invalid. Check Log Console for more detail."
            break
        case KPFError_EnterpriseNotFound:
            NSLog("KPFramework Error: Enterprise is not found. Please contact us for support")
            
            msg = "Enterprise is not found. Check Log Console for more detail."
            break
        case KPFError_WrongClientKeyType:
            NSLog("KPFramework Error: ClientKeyType is wrong. Please NOT using server key on client sdk or using client key on server")
            
            msg = "ClientKeyType is wrong. Please NOT using server key on client sdk or using client key on server. Check Log Console for more detail."
            break
        case kPFError_User_Identity_Is_Null:
            NSLog("KPFramework Error: User Identity can not be nil.")
            
            msg = "User Identity can not be nil. Check Log Console for more detail."
            break
        case KPFError_Language_Not_Supported:
            NSLog("KPFramework Error: Localized language is not supported by SDK. Please check enum KPFSupportedLocalization to get supported langugages by the SDK")
            
            msg = "Localized language is not supported by SDK. Check Log Console for more detail."
            break
        case KPFError_Requested_Amount_Must_Be_Greater_Than_Zero:
            NSLog("KPFramework Error: Requested Amount must be greater than zero")
            
            msg = "Requested Amount must be greater than zero. Check Log Console for more detail."
            break
        default:
            NSLog("KPFramework Error: NO ERROR. SDK is canceled by user OR successful top up. Get value of paymentId for case successful top up")
            
            if let pId = paymentId {
                self.lbResult.text = "PaymentID : \(pId)"
                
                UIPasteboard.general.string = pId
            }
            
            return
        }
        
        self.showAlert(message: msg)
    }
}

class AmountView : UIView {
    
    let bgButton = UIButton(type: .custom)
    let amountTextfield = UITextField()
    let openButton = UIButton(type: .custom)

    var openBlock : ((Double) -> ())? = nil
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        self.bgButton.frame = CGRect(x: 0, y: 0, width: self.frame.size.width, height: self.frame.size.height)
        self.bgButton.backgroundColor = .black
        self.bgButton.alpha = 0.8
        self.bgButton.addTarget(self, action: #selector(closePopup(sender:)), for: .touchUpInside)
        self.addSubview(self.bgButton)
        
        self.amountTextfield.frame = CGRect(x: 20, y: 70, width: self.frame.size.width - 20*2, height: 50)
        self.amountTextfield.backgroundColor = .white
        self.amountTextfield.textAlignment = .left
        self.amountTextfield.textColor = .black
        self.amountTextfield.font = UIFont.boldSystemFont(ofSize: 14)
        self.amountTextfield.keyboardType = .decimalPad
        self.amountTextfield.placeholder = "Enter requested amount"
        self.amountTextfield.leftView = UIView(frame: CGRect(x: 0, y: 0, width: 10, height: 0))
        self.amountTextfield.leftViewMode = .always
        self.addSubview(self.amountTextfield)
        
        let y = self.amountTextfield.frame.origin.y + self.amountTextfield.frame.size.height + 40
        self.openButton.frame = CGRect(x: 40, y: y, width: self.frame.size.width - 40*2, height: 50)
        self.openButton.layer.borderColor = UIColor.white.cgColor
        self.openButton.layer.borderWidth = 1
        self.openButton.setTitle("OPEN SDK", for: .normal)
        self.openButton.setTitleColor(.white, for: .normal)
        self.openButton.addTarget(self, action: #selector(openSDK(sender:)), for: .touchUpInside)
        self.addSubview(self.openButton)
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.3, execute: {
            self.amountTextfield.becomeFirstResponder()
        })
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    deinit {
        
    }
    
    @objc func closePopup(sender : Any) {
        self.amountTextfield.resignFirstResponder()
        
        self.removeFromSuperview()
    }
    
    @objc func openSDK(sender : Any) {
        if self.amountTextfield.text == nil || self.amountTextfield.text == "" {
            self.openBlock?(-1)
            return
        }
        
        if let d = Double(self.amountTextfield.text!) {

            if d > 0 {
                self.openBlock?(d)
                self.removeFromSuperview()
            } else {
                self.openBlock?(-1)
            }
        } else {
            self.openBlock?(-1)
        }
    }
}

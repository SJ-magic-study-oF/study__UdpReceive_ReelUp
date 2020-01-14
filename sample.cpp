
/******************************
基本は、
	of_v0.11.0_osx_release/examples/communication/networkUdpReceiverExample/src
で良いが、送信側と受信側でFrameRateが異なる場合に、きちんと巻き取ってやらないと、
どんどんdataが積もってしまう。

そこで以下のように対応すること。
******************************/
void ofApp::GetUdp_UpdateData(ofxUDPManager& udp_Receive){
	char udpMessage[BUF_SIZE_LL];
	udp_Receive.Receive(udpMessage, BUF_SIZE_LL);
	
	string message=udpMessage;
	if(message!=""){
		string LastMessage = message;
		
		do{ // 巻き取り
			udp_Receive.Receive(udpMessage, BUF_SIZE_LL);
			message = udpMessage;
			if(message != "") LastMessage = message;
			
		}while(message != "");
		
		vector<string> strMessage = ofSplitString(LastMessage, "<p>");
		
		if(strMessage[0] == "/Golem/SkeletonData"){
			// do something.
		}else if(strMessage[0] == "/UnityApp/Scene"){
			// do something.
		}
	}
}


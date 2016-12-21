function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Pulse
Generator */
	this.urlHashMap["ledBlink:2"] = "ledBlink.c:36,46,77&ledBlink.h:46,55,58,61,64&ledBlink_data.c:29,32,35,38";
	/* <S1>/Data Type Conversion */
	this.urlHashMap["ledBlink:1:114"] = "ledBlink.c:48,59";
	/* <S1>/Digital Output */
	this.urlHashMap["ledBlink:1:214"] = "ledBlink.c:61,80&ledBlink.h:52&ledBlink_data.c:26";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "ledBlink"};
	this.sidHashMap["ledBlink"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "ledBlink:1"};
	this.sidHashMap["ledBlink:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Digital Output"] = {sid: "ledBlink:1"};
	this.sidHashMap["ledBlink:1"] = {rtwname: "<Root>/Digital Output"};
	this.rtwnameHashMap["<Root>/Pulse Generator"] = {sid: "ledBlink:2"};
	this.sidHashMap["ledBlink:2"] = {rtwname: "<Root>/Pulse Generator"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "ledBlink:1:116"};
	this.sidHashMap["ledBlink:1:116"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/Data Type Conversion"] = {sid: "ledBlink:1:114"};
	this.sidHashMap["ledBlink:1:114"] = {rtwname: "<S1>/Data Type Conversion"};
	this.rtwnameHashMap["<S1>/Digital Output"] = {sid: "ledBlink:1:214"};
	this.sidHashMap["ledBlink:1:214"] = {rtwname: "<S1>/Digital Output"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

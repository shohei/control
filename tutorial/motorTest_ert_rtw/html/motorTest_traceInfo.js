function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["motorTest:13"] = "motorTest.c:40&motorTest.h:103&motorTest_data.c:32";
	/* <Root>/Constant1 */
	this.urlHashMap["motorTest:14"] = "motorTest.c:56&motorTest.h:106&motorTest_data.c:35";
	/* <Root>/Constant2 */
	this.urlHashMap["motorTest:3"] = "motorTest.c:72&motorTest.h:109&motorTest_data.c:38";
	/* <Root>/Data Type Conversion1 */
	this.urlHashMap["motorTest:4"] = "motorTest.c:71,84&motorTest.h:86";
	/* <Root>/Data Type Conversion2 */
	this.urlHashMap["motorTest:11"] = "motorTest.c:55,69&motorTest.h:85";
	/* <Root>/Data Type Conversion3 */
	this.urlHashMap["motorTest:12"] = "motorTest.c:39,53&motorTest.h:84";
	/* <Root>/S-Function Builder1 */
	this.urlHashMap["motorTest:7"] = "motorTest.c:86,91,184&motorTest.h:91";
	/* <S1>/Slider
Gain */
	this.urlHashMap["motorTest:9:31"] = "motorTest.c:41&motorTest.h:97&motorTest_data.c:26";
	/* <S2>/Slider
Gain */
	this.urlHashMap["motorTest:10:31"] = "motorTest.c:57&motorTest.h:100&motorTest_data.c:29";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "motorTest"};
	this.sidHashMap["motorTest"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "motorTest:9"};
	this.sidHashMap["motorTest:9"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "motorTest:10"};
	this.sidHashMap["motorTest:10"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "motorTest:13"};
	this.sidHashMap["motorTest:13"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "motorTest:14"};
	this.sidHashMap["motorTest:14"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "motorTest:3"};
	this.sidHashMap["motorTest:3"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "motorTest:4"};
	this.sidHashMap["motorTest:4"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Data Type Conversion2"] = {sid: "motorTest:11"};
	this.sidHashMap["motorTest:11"] = {rtwname: "<Root>/Data Type Conversion2"};
	this.rtwnameHashMap["<Root>/Data Type Conversion3"] = {sid: "motorTest:12"};
	this.sidHashMap["motorTest:12"] = {rtwname: "<Root>/Data Type Conversion3"};
	this.rtwnameHashMap["<Root>/S-Function Builder1"] = {sid: "motorTest:7"};
	this.sidHashMap["motorTest:7"] = {rtwname: "<Root>/S-Function Builder1"};
	this.rtwnameHashMap["<Root>/Slider Gain"] = {sid: "motorTest:9"};
	this.sidHashMap["motorTest:9"] = {rtwname: "<Root>/Slider Gain"};
	this.rtwnameHashMap["<Root>/Slider Gain1"] = {sid: "motorTest:10"};
	this.sidHashMap["motorTest:10"] = {rtwname: "<Root>/Slider Gain1"};
	this.rtwnameHashMap["<S1>/u"] = {sid: "motorTest:9:30"};
	this.sidHashMap["motorTest:9:30"] = {rtwname: "<S1>/u"};
	this.rtwnameHashMap["<S1>/Slider Gain"] = {sid: "motorTest:9:31"};
	this.sidHashMap["motorTest:9:31"] = {rtwname: "<S1>/Slider Gain"};
	this.rtwnameHashMap["<S1>/y"] = {sid: "motorTest:9:32"};
	this.sidHashMap["motorTest:9:32"] = {rtwname: "<S1>/y"};
	this.rtwnameHashMap["<S2>/u"] = {sid: "motorTest:10:30"};
	this.sidHashMap["motorTest:10:30"] = {rtwname: "<S2>/u"};
	this.rtwnameHashMap["<S2>/Slider Gain"] = {sid: "motorTest:10:31"};
	this.sidHashMap["motorTest:10:31"] = {rtwname: "<S2>/Slider Gain"};
	this.rtwnameHashMap["<S2>/y"] = {sid: "motorTest:10:32"};
	this.sidHashMap["motorTest:10:32"] = {rtwname: "<S2>/y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

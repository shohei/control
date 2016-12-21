function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["test:2"] = "test.c:39&test.h:68&test_data.c:32";
	/* <Root>/Constant1 */
	this.urlHashMap["test:3"] = "test.c:55&test.h:71&test_data.c:35";
	/* <Root>/Constant2 */
	this.urlHashMap["test:7"] = "test.c:87&test.h:65&test_data.c:29";
	/* <Root>/Constant5 */
	this.urlHashMap["test:19"] = "test.c:101&test.h:62&test_data.c:26";
	/* <Root>/Data Type Conversion1 */
	this.urlHashMap["test:10"] = "test.c:82,86";
	/* <Root>/Data Type Conversion2 */
	this.urlHashMap["test:11"] = "test.c:54,68&test.h:49";
	/* <Root>/Data Type Conversion3 */
	this.urlHashMap["test:12"] = "test.c:38,52&test.h:48";
	/* <Root>/Data Type Conversion4 */
	this.urlHashMap["test:20"] = "test.c:83,100";
	/* <Root>/Pulse
Generator */
	this.urlHashMap["test:13"] = "test.c:70,79,147&test.h:56,74,77,80,83&test_data.c:38,41,44,47";
	/* <Root>/S-Function Builder */
	this.urlHashMap["test:1"] = "test.c:117,122,150&test.h:55";
	/* <Root>/Switch */
	this.urlHashMap["test:15"] = "test.c:81,115&test.h:50,86&test_data.c:50";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "test"};
	this.sidHashMap["test"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "test:2"};
	this.sidHashMap["test:2"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "test:3"};
	this.sidHashMap["test:3"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "test:7"};
	this.sidHashMap["test:7"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Constant5"] = {sid: "test:19"};
	this.sidHashMap["test:19"] = {rtwname: "<Root>/Constant5"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "test:10"};
	this.sidHashMap["test:10"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Data Type Conversion2"] = {sid: "test:11"};
	this.sidHashMap["test:11"] = {rtwname: "<Root>/Data Type Conversion2"};
	this.rtwnameHashMap["<Root>/Data Type Conversion3"] = {sid: "test:12"};
	this.sidHashMap["test:12"] = {rtwname: "<Root>/Data Type Conversion3"};
	this.rtwnameHashMap["<Root>/Data Type Conversion4"] = {sid: "test:20"};
	this.sidHashMap["test:20"] = {rtwname: "<Root>/Data Type Conversion4"};
	this.rtwnameHashMap["<Root>/Pulse Generator"] = {sid: "test:13"};
	this.sidHashMap["test:13"] = {rtwname: "<Root>/Pulse Generator"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "test:1"};
	this.sidHashMap["test:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Switch"] = {sid: "test:15"};
	this.sidHashMap["test:15"] = {rtwname: "<Root>/Switch"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["test3:1"] = "test3.c:39&test3.h:68&test3_data.c:32";
	/* <Root>/Constant1 */
	this.urlHashMap["test3:2"] = "test3.c:55&test3.h:71&test3_data.c:35";
	/* <Root>/Constant2 */
	this.urlHashMap["test3:3"] = "test3.c:87&test3.h:65&test3_data.c:29";
	/* <Root>/Constant5 */
	this.urlHashMap["test3:4"] = "test3.c:101&test3.h:62&test3_data.c:26";
	/* <Root>/Data Type Conversion1 */
	this.urlHashMap["test3:5"] = "test3.c:82,86";
	/* <Root>/Data Type Conversion2 */
	this.urlHashMap["test3:6"] = "test3.c:54,68&test3.h:49";
	/* <Root>/Data Type Conversion3 */
	this.urlHashMap["test3:7"] = "test3.c:38,52&test3.h:48";
	/* <Root>/Data Type Conversion4 */
	this.urlHashMap["test3:8"] = "test3.c:83,100";
	/* <Root>/Pulse
Generator */
	this.urlHashMap["test3:9"] = "test3.c:70,79,147&test3.h:56,74,77,80,83&test3_data.c:38,41,44,47";
	/* <Root>/S-Function Builder */
	this.urlHashMap["test3:10"] = "test3.c:117,122,150&test3.h:55";
	/* <Root>/Switch */
	this.urlHashMap["test3:11"] = "test3.c:81,115&test3.h:50,86&test3_data.c:50";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "test3"};
	this.sidHashMap["test3"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "test3:1"};
	this.sidHashMap["test3:1"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "test3:2"};
	this.sidHashMap["test3:2"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "test3:3"};
	this.sidHashMap["test3:3"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Constant5"] = {sid: "test3:4"};
	this.sidHashMap["test3:4"] = {rtwname: "<Root>/Constant5"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "test3:5"};
	this.sidHashMap["test3:5"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Data Type Conversion2"] = {sid: "test3:6"};
	this.sidHashMap["test3:6"] = {rtwname: "<Root>/Data Type Conversion2"};
	this.rtwnameHashMap["<Root>/Data Type Conversion3"] = {sid: "test3:7"};
	this.sidHashMap["test3:7"] = {rtwname: "<Root>/Data Type Conversion3"};
	this.rtwnameHashMap["<Root>/Data Type Conversion4"] = {sid: "test3:8"};
	this.sidHashMap["test3:8"] = {rtwname: "<Root>/Data Type Conversion4"};
	this.rtwnameHashMap["<Root>/Pulse Generator"] = {sid: "test3:9"};
	this.sidHashMap["test3:9"] = {rtwname: "<Root>/Pulse Generator"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "test3:10"};
	this.sidHashMap["test3:10"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Switch"] = {sid: "test3:11"};
	this.sidHashMap["test3:11"] = {rtwname: "<Root>/Switch"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

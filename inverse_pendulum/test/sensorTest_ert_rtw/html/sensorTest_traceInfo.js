function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/S-Function Builder */
	this.urlHashMap["sensorTest:1"] = "sensorTest.c:37,41,127&sensorTest.h:81,86";
	/* <Root>/Scope */
	this.urlHashMap["sensorTest:2"] = "sensorTest.h:89";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "sensorTest"};
	this.sidHashMap["sensorTest"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "sensorTest:1"};
	this.sidHashMap["sensorTest:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "sensorTest:2"};
	this.sidHashMap["sensorTest:2"] = {rtwname: "<Root>/Scope"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/S-Function Builder */
	this.urlHashMap["sensorTest2:1"] = "sensorTest2.c:37,41,128&sensorTest2.h:81,86";
	/* <Root>/Scope */
	this.urlHashMap["sensorTest2:2"] = "sensorTest2.h:89";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "sensorTest2"};
	this.sidHashMap["sensorTest2"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "sensorTest2:1"};
	this.sidHashMap["sensorTest2:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "sensorTest2:2"};
	this.sidHashMap["sensorTest2:2"] = {rtwname: "<Root>/Scope"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

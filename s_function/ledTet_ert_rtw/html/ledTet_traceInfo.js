function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["ledTet:2"] = "ledTet.c:40&ledTet.h:95&ledTet_data.c:26";
	/* <Root>/Data Type Conversion */
	this.urlHashMap["ledTet:3"] = "ledTet.c:39,52&ledTet.h:84";
	/* <Root>/S-Function Builder */
	this.urlHashMap["ledTet:1"] = "ledTet.c:54,58,150&ledTet.h:89";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "ledTet"};
	this.sidHashMap["ledTet"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "ledTet:2"};
	this.sidHashMap["ledTet:2"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Data Type Conversion"] = {sid: "ledTet:3"};
	this.sidHashMap["ledTet:3"] = {rtwname: "<Root>/Data Type Conversion"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "ledTet:1"};
	this.sidHashMap["ledTet:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/S-Function Builder */
	this.urlHashMap["mpu6050:1"] = "mpu6050.c:37,42,129&mpu6050.h:86";
	/* <Root>/Scope */
	this.urlHashMap["mpu6050:3"] = "mpu6050.h:89";
	/* <Root>/Vector
Concatenate */
	this.urlHashMap["mpu6050:2"] = "mpu6050.h:81";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "mpu6050"};
	this.sidHashMap["mpu6050"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "mpu6050:1"};
	this.sidHashMap["mpu6050:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "mpu6050:3"};
	this.sidHashMap["mpu6050:3"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Vector Concatenate"] = {sid: "mpu6050:2"};
	this.sidHashMap["mpu6050:2"] = {rtwname: "<Root>/Vector Concatenate"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

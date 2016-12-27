function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/S-Function Builder */
	this.urlHashMap["mpu6050_test:1"] = "mpu6050_test.c:37,42,130&mpu6050_test.h:86";
	/* <Root>/Scope */
	this.urlHashMap["mpu6050_test:2"] = "mpu6050_test.h:89";
	/* <Root>/Vector
Concatenate */
	this.urlHashMap["mpu6050_test:3"] = "mpu6050_test.h:81";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "mpu6050_test"};
	this.sidHashMap["mpu6050_test"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "mpu6050_test:1"};
	this.sidHashMap["mpu6050_test:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "mpu6050_test:2"};
	this.sidHashMap["mpu6050_test:2"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Vector Concatenate"] = {sid: "mpu6050_test:3"};
	this.sidHashMap["mpu6050_test:3"] = {rtwname: "<Root>/Vector Concatenate"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

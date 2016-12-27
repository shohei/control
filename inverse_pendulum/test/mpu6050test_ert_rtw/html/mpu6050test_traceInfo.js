function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Display */
	this.urlHashMap["mpu6050test:2"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=mpu6050test:2";
	/* <Root>/Display1 */
	this.urlHashMap["mpu6050test:3"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=mpu6050test:3";
	/* <Root>/Display2 */
	this.urlHashMap["mpu6050test:4"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=mpu6050test:4";
	/* <Root>/S-Function Builder */
	this.urlHashMap["mpu6050test:1"] = "mpu6050test.c:37,51,139&mpu6050test.h:81,82,83,89";
	/* <Root>/Scope */
	this.urlHashMap["mpu6050test:5"] = "mpu6050test.h:92";
	/* <Root>/To Workspace */
	this.urlHashMap["mpu6050test:7"] = "mpu6050test.h:96";
	/* <Root>/Vector
Concatenate */
	this.urlHashMap["mpu6050test:6"] = "mpu6050test.h:84";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "mpu6050test"};
	this.sidHashMap["mpu6050test"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Display"] = {sid: "mpu6050test:2"};
	this.sidHashMap["mpu6050test:2"] = {rtwname: "<Root>/Display"};
	this.rtwnameHashMap["<Root>/Display1"] = {sid: "mpu6050test:3"};
	this.sidHashMap["mpu6050test:3"] = {rtwname: "<Root>/Display1"};
	this.rtwnameHashMap["<Root>/Display2"] = {sid: "mpu6050test:4"};
	this.sidHashMap["mpu6050test:4"] = {rtwname: "<Root>/Display2"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "mpu6050test:1"};
	this.sidHashMap["mpu6050test:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "mpu6050test:5"};
	this.sidHashMap["mpu6050test:5"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/To Workspace"] = {sid: "mpu6050test:7"};
	this.sidHashMap["mpu6050test:7"] = {rtwname: "<Root>/To Workspace"};
	this.rtwnameHashMap["<Root>/Vector Concatenate"] = {sid: "mpu6050test:6"};
	this.sidHashMap["mpu6050test:6"] = {rtwname: "<Root>/Vector Concatenate"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

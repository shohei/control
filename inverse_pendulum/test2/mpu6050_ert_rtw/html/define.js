function CodeDefine() { 
this.def = new Array();
this.def["IsrOverrun"] = {file: "ert_main_c.html",line:27,type:"var"};
this.def["OverrunFlag"] = {file: "ert_main_c.html",line:28,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:29,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:57,type:"fcn"};
this.def["mpu6050_B"] = {file: "mpu6050_c.html",line:25,type:"var"};
this.def["mpu6050_DW"] = {file: "mpu6050_c.html",line:28,type:"var"};
this.def["mpu6050_M_"] = {file: "mpu6050_c.html",line:31,type:"var"};
this.def["mpu6050_M"] = {file: "mpu6050_c.html",line:32,type:"var"};
this.def["mpu6050_step"] = {file: "mpu6050_c.html",line:35,type:"fcn"};
this.def["mpu6050_initialize"] = {file: "mpu6050_c.html",line:78,type:"fcn"};
this.def["mpu6050_terminate"] = {file: "mpu6050_c.html",line:143,type:"fcn"};
this.def["B_mpu6050_T"] = {file: "mpu6050_h.html",line:82,type:"type"};
this.def["DW_mpu6050_T"] = {file: "mpu6050_h.html",line:90,type:"type"};
this.def["RT_MODEL_mpu6050_T"] = {file: "mpu6050_types_h.html",line:24,type:"type"};
this.def["chunk_T"] = {file: "multiword_types_h.html",line:27,type:"type"};
this.def["uchunk_T"] = {file: "multiword_types_h.html",line:28,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:82,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:87,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:92,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:99,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:106,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:113,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:120,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:127,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:134,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:152,type:"type"};
this.def["rtDataTypeSizes"] = {file: "mpu6050_dt_h.html",line:23,type:"var"};
this.def["rtDataTypeNames"] = {file: "mpu6050_dt_h.html",line:41,type:"var"};
this.def["rtBTransitions"] = {file: "mpu6050_dt_h.html",line:59,type:"var"};
this.def["rtBTransTable"] = {file: "mpu6050_dt_h.html",line:69,type:"var"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "/";
var isPC = false;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["mpu6050_c.html"] = "../mpu6050.c";
	this.html2Root["mpu6050_c.html"] = "mpu6050_c.html";
	this.html2SrcPath["mpu6050_h.html"] = "../mpu6050.h";
	this.html2Root["mpu6050_h.html"] = "mpu6050_h.html";
	this.html2SrcPath["mpu6050_private_h.html"] = "../mpu6050_private.h";
	this.html2Root["mpu6050_private_h.html"] = "mpu6050_private_h.html";
	this.html2SrcPath["mpu6050_types_h.html"] = "../mpu6050_types.h";
	this.html2Root["mpu6050_types_h.html"] = "mpu6050_types_h.html";
	this.html2SrcPath["multiword_types_h.html"] = "../multiword_types.h";
	this.html2Root["multiword_types_h.html"] = "multiword_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["mpu6050_dt_h.html"] = "../mpu6050_dt.h";
	this.html2Root["mpu6050_dt_h.html"] = "mpu6050_dt_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.html2SrcPath["MW_target_hardware_resources_h.html"] = "../MW_target_hardware_resources.h";
	this.html2Root["MW_target_hardware_resources_h.html"] = "MW_target_hardware_resources_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","mpu6050_c.html","mpu6050_h.html","mpu6050_private_h.html","mpu6050_types_h.html","multiword_types_h.html","rtwtypes_h.html","mpu6050_dt_h.html","rtmodel_h.html","MW_target_hardware_resources_h.html"];

function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["test2:2"] = "test2.c:41&test2.h:135&test2_data.c:50";
	/* <Root>/Constant1 */
	this.urlHashMap["test2:3"] = "test2.c:57&test2.h:138&test2_data.c:53";
	/* <Root>/Constant2 */
	this.urlHashMap["test2:4"] = "test2.c:89&test2.h:132&test2_data.c:47";
	/* <Root>/Constant5 */
	this.urlHashMap["test2:5"] = "test2.c:103&test2.h:129&test2_data.c:44";
	/* <Root>/Data Type Conversion1 */
	this.urlHashMap["test2:6"] = "test2.c:84,88";
	/* <Root>/Data Type Conversion10 */
	this.urlHashMap["test2:28"] = "msg=rtwMsg_reducedBlock&block=test2:28";
	/* <Root>/Data Type Conversion2 */
	this.urlHashMap["test2:7"] = "test2.c:56,70&test2.h:87";
	/* <Root>/Data Type Conversion3 */
	this.urlHashMap["test2:8"] = "test2.c:40,54&test2.h:86";
	/* <Root>/Data Type Conversion4 */
	this.urlHashMap["test2:9"] = "test2.c:85,102";
	/* <Root>/Data Type Conversion5 */
	this.urlHashMap["test2:23"] = "msg=rtwMsg_reducedBlock&block=test2:23";
	/* <Root>/Data Type Conversion6 */
	this.urlHashMap["test2:24"] = "msg=rtwMsg_reducedBlock&block=test2:24";
	/* <Root>/Data Type Conversion7 */
	this.urlHashMap["test2:25"] = "msg=rtwMsg_reducedBlock&block=test2:25";
	/* <Root>/Data Type Conversion8 */
	this.urlHashMap["test2:26"] = "msg=rtwMsg_reducedBlock&block=test2:26";
	/* <Root>/Data Type Conversion9 */
	this.urlHashMap["test2:27"] = "msg=rtwMsg_reducedBlock&block=test2:27";
	/* <Root>/Pulse
Generator */
	this.urlHashMap["test2:10"] = "test2.c:72,81,300&test2.h:105,141,144,147,150&test2_data.c:56,59,62,65";
	/* <Root>/S-Function Builder */
	this.urlHashMap["test2:11"] = "test2.c:119,202,321&test2.h:89,90,91,92,93,94,100";
	/* <Root>/Scope */
	this.urlHashMap["test2:29"] = "test2.h:103";
	/* <Root>/Switch */
	this.urlHashMap["test2:12"] = "test2.c:83,117&test2.h:88,153&test2_data.c:68";
	/* <Root>/Vector
Concatenate */
	this.urlHashMap["test2:30"] = "test2.h:95";
	/* <S1>/Data Type Conversion */
	this.urlHashMap["test2:17:114"] = "test2.c:127,134";
	/* <S1>/Digital Output */
	this.urlHashMap["test2:17:214"] = "test2.c:133,303&test2.h:111&test2_data.c:26";
	/* <S2>/Data Type Conversion */
	this.urlHashMap["test2:18:114"] = "test2.c:138,145";
	/* <S2>/Digital Output */
	this.urlHashMap["test2:18:214"] = "test2.c:144,306&test2.h:114&test2_data.c:29";
	/* <S3>/Data Type Conversion */
	this.urlHashMap["test2:19:114"] = "test2.c:149,156";
	/* <S3>/Digital Output */
	this.urlHashMap["test2:19:214"] = "test2.c:155,309&test2.h:117&test2_data.c:32";
	/* <S4>/Data Type Conversion */
	this.urlHashMap["test2:20:114"] = "test2.c:160,167";
	/* <S4>/Digital Output */
	this.urlHashMap["test2:20:214"] = "test2.c:166,312&test2.h:120&test2_data.c:35";
	/* <S5>/Data Type Conversion */
	this.urlHashMap["test2:21:114"] = "test2.c:171,178";
	/* <S5>/PWM */
	this.urlHashMap["test2:21:215"] = "test2.c:177,315&test2.h:123&test2_data.c:38";
	/* <S6>/Data Type Conversion */
	this.urlHashMap["test2:22:114"] = "test2.c:182,189";
	/* <S6>/PWM */
	this.urlHashMap["test2:22:215"] = "test2.c:188,318&test2.h:126&test2_data.c:41";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "test2"};
	this.sidHashMap["test2"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "test2:17"};
	this.sidHashMap["test2:17"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "test2:18"};
	this.sidHashMap["test2:18"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "test2:19"};
	this.sidHashMap["test2:19"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "test2:20"};
	this.sidHashMap["test2:20"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "test2:21"};
	this.sidHashMap["test2:21"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "test2:22"};
	this.sidHashMap["test2:22"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "test2:2"};
	this.sidHashMap["test2:2"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "test2:3"};
	this.sidHashMap["test2:3"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "test2:4"};
	this.sidHashMap["test2:4"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Constant5"] = {sid: "test2:5"};
	this.sidHashMap["test2:5"] = {rtwname: "<Root>/Constant5"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "test2:6"};
	this.sidHashMap["test2:6"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Data Type Conversion10"] = {sid: "test2:28"};
	this.sidHashMap["test2:28"] = {rtwname: "<Root>/Data Type Conversion10"};
	this.rtwnameHashMap["<Root>/Data Type Conversion2"] = {sid: "test2:7"};
	this.sidHashMap["test2:7"] = {rtwname: "<Root>/Data Type Conversion2"};
	this.rtwnameHashMap["<Root>/Data Type Conversion3"] = {sid: "test2:8"};
	this.sidHashMap["test2:8"] = {rtwname: "<Root>/Data Type Conversion3"};
	this.rtwnameHashMap["<Root>/Data Type Conversion4"] = {sid: "test2:9"};
	this.sidHashMap["test2:9"] = {rtwname: "<Root>/Data Type Conversion4"};
	this.rtwnameHashMap["<Root>/Data Type Conversion5"] = {sid: "test2:23"};
	this.sidHashMap["test2:23"] = {rtwname: "<Root>/Data Type Conversion5"};
	this.rtwnameHashMap["<Root>/Data Type Conversion6"] = {sid: "test2:24"};
	this.sidHashMap["test2:24"] = {rtwname: "<Root>/Data Type Conversion6"};
	this.rtwnameHashMap["<Root>/Data Type Conversion7"] = {sid: "test2:25"};
	this.sidHashMap["test2:25"] = {rtwname: "<Root>/Data Type Conversion7"};
	this.rtwnameHashMap["<Root>/Data Type Conversion8"] = {sid: "test2:26"};
	this.sidHashMap["test2:26"] = {rtwname: "<Root>/Data Type Conversion8"};
	this.rtwnameHashMap["<Root>/Data Type Conversion9"] = {sid: "test2:27"};
	this.sidHashMap["test2:27"] = {rtwname: "<Root>/Data Type Conversion9"};
	this.rtwnameHashMap["<Root>/Digital Output"] = {sid: "test2:17"};
	this.sidHashMap["test2:17"] = {rtwname: "<Root>/Digital Output"};
	this.rtwnameHashMap["<Root>/Digital Output1"] = {sid: "test2:18"};
	this.sidHashMap["test2:18"] = {rtwname: "<Root>/Digital Output1"};
	this.rtwnameHashMap["<Root>/Digital Output2"] = {sid: "test2:19"};
	this.sidHashMap["test2:19"] = {rtwname: "<Root>/Digital Output2"};
	this.rtwnameHashMap["<Root>/Digital Output3"] = {sid: "test2:20"};
	this.sidHashMap["test2:20"] = {rtwname: "<Root>/Digital Output3"};
	this.rtwnameHashMap["<Root>/PWM"] = {sid: "test2:21"};
	this.sidHashMap["test2:21"] = {rtwname: "<Root>/PWM"};
	this.rtwnameHashMap["<Root>/PWM1"] = {sid: "test2:22"};
	this.sidHashMap["test2:22"] = {rtwname: "<Root>/PWM1"};
	this.rtwnameHashMap["<Root>/Pulse Generator"] = {sid: "test2:10"};
	this.sidHashMap["test2:10"] = {rtwname: "<Root>/Pulse Generator"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "test2:11"};
	this.sidHashMap["test2:11"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "test2:29"};
	this.sidHashMap["test2:29"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Switch"] = {sid: "test2:12"};
	this.sidHashMap["test2:12"] = {rtwname: "<Root>/Switch"};
	this.rtwnameHashMap["<Root>/Vector Concatenate"] = {sid: "test2:30"};
	this.sidHashMap["test2:30"] = {rtwname: "<Root>/Vector Concatenate"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "test2:17:116"};
	this.sidHashMap["test2:17:116"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/Data Type Conversion"] = {sid: "test2:17:114"};
	this.sidHashMap["test2:17:114"] = {rtwname: "<S1>/Data Type Conversion"};
	this.rtwnameHashMap["<S1>/Digital Output"] = {sid: "test2:17:214"};
	this.sidHashMap["test2:17:214"] = {rtwname: "<S1>/Digital Output"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "test2:18:116"};
	this.sidHashMap["test2:18:116"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/Data Type Conversion"] = {sid: "test2:18:114"};
	this.sidHashMap["test2:18:114"] = {rtwname: "<S2>/Data Type Conversion"};
	this.rtwnameHashMap["<S2>/Digital Output"] = {sid: "test2:18:214"};
	this.sidHashMap["test2:18:214"] = {rtwname: "<S2>/Digital Output"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "test2:19:116"};
	this.sidHashMap["test2:19:116"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/Data Type Conversion"] = {sid: "test2:19:114"};
	this.sidHashMap["test2:19:114"] = {rtwname: "<S3>/Data Type Conversion"};
	this.rtwnameHashMap["<S3>/Digital Output"] = {sid: "test2:19:214"};
	this.sidHashMap["test2:19:214"] = {rtwname: "<S3>/Digital Output"};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "test2:20:116"};
	this.sidHashMap["test2:20:116"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/Data Type Conversion"] = {sid: "test2:20:114"};
	this.sidHashMap["test2:20:114"] = {rtwname: "<S4>/Data Type Conversion"};
	this.rtwnameHashMap["<S4>/Digital Output"] = {sid: "test2:20:214"};
	this.sidHashMap["test2:20:214"] = {rtwname: "<S4>/Digital Output"};
	this.rtwnameHashMap["<S5>/In1"] = {sid: "test2:21:116"};
	this.sidHashMap["test2:21:116"] = {rtwname: "<S5>/In1"};
	this.rtwnameHashMap["<S5>/Data Type Conversion"] = {sid: "test2:21:114"};
	this.sidHashMap["test2:21:114"] = {rtwname: "<S5>/Data Type Conversion"};
	this.rtwnameHashMap["<S5>/PWM"] = {sid: "test2:21:215"};
	this.sidHashMap["test2:21:215"] = {rtwname: "<S5>/PWM"};
	this.rtwnameHashMap["<S6>/In1"] = {sid: "test2:22:116"};
	this.sidHashMap["test2:22:116"] = {rtwname: "<S6>/In1"};
	this.rtwnameHashMap["<S6>/Data Type Conversion"] = {sid: "test2:22:114"};
	this.sidHashMap["test2:22:114"] = {rtwname: "<S6>/Data Type Conversion"};
	this.rtwnameHashMap["<S6>/PWM"] = {sid: "test2:22:215"};
	this.sidHashMap["test2:22:215"] = {rtwname: "<S6>/PWM"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

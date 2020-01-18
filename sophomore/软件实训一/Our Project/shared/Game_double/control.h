#ifndef CONTROL_H
#define CONTROL_H
//该文件包含了所有实例化对象

#include "classes.h"
//房产
static CHouse Lib1("图书馆一号", 10);
static CHouse Jzl("纪忠楼树林", 4);
static CHouse Xmwoods1("西门小树林一号", 4);
static CHouse Xmwoods2("西门小树林二号", 4);
static CHouse Qrp1("情人坡一号", 6);
static CHouse Qrp2("情人坡二号", 6);
static CHouse Jlh1("九龙湖宾馆一号", 8);
static CHouse Jlh2("九龙湖宾馆二号", 8);
static CHouse Bmwoods1("北门小树林一号", 4);
static CHouse Bmwoods2("北门小树林二号", 4);
static CHouse Wkl1("文科楼一号", 8);
static CHouse Wkl2("文科楼二号", 8);
static CHouse Lib2("图书馆二号", 10);
static CHouse Lib3("图书馆三号", 10);
static CHouse Bmhc("北门花池", 6);
static CHouse T56("桃56", 4);
static CHouse T34("桃34", 4);
static CHouse T12("桃12", 4);
static CHouse M58("梅58", 4);
static CHouse M14("梅14", 4);
static CHouse Mgy("玫瑰园", 6);
static CHouse Myhc("梅园小花池", 6);
static CHouse Xqf1("学区房一号", 10);
static CHouse Xqf2("学区房二号", 10);
static CHouse Lib4("图书馆四号", 10);
static CHouse Jydom("橘园宿舍区", 6);
static CHouse Xzlwoods("行政楼小树林", 4);
static CHouse Nmwoods1("南门小树林一号", 4);
static CHouse Zyddhy("中央大道花园", 6);
static CHouse Nmwoods2("南门小树林二号", 4);

const int g_numOfhouses = 30;

static CHouse * houses[] = {&Lib1, &Jzl, &Xmwoods1, &Xmwoods2, &Qrp1, &Qrp2, &Jlh1, &Jlh2, &Bmwoods1, &Bmwoods2, &Wkl2, &Wkl2, &Lib2, &Lib3, &Bmhc,
                         &T56, &T34, &T12, &M58, &M14, &Mgy, &Myhc, &Xqf1, &Xqf2, &Lib4, &Jydom, &Xzlwoods, &Nmwoods1, &Zyddhy, &Nmwoods2};


//共有多少事件
const int g_numOfEvents = 80;

//学分事件实例化
static CEvent * sj01 = new CCreditChangeEvent("sj01", "在图书馆内刻苦学习，加10个学分", 10);
static CEvent * sj02 = new CCreditChangeEvent("sj02", "在图书馆勤工俭学，加5个学分", 5);
static CEvent * sj03 = new CCreditChangeEvent("sj03", "翘课去西门去快递被发现，扣3个学分", -3);
static CEvent * sj04 = new CCreditChangeEvent("sj04", "在九龙湖边眺望湖中美景，心旷神怡", 0);
static CEvent * sj05 = new CCreditChangeEvent("sj05", "考试周未认真复习马原，导致挂科，扣5学分", -5);
static CEvent * sj06 = new CCreditChangeEvent("sj06", "经过认真的学习，经管类选修得优，加5个学分", 5);
static CEvent * sj07 = new CCreditChangeEvent("sj07", "在化学楼完成化学实验，表现良好，加5个学分", 5);
static CEvent * sj08 = new CCreditChangeEvent("sj08", "本科阶段研发出新型材料，获得嘉奖，奖励15学分", 15);
static CEvent * sj09 = new CCreditChangeEvent("sj09", "结构竞赛获一等奖，奖励5学分", 5);
static CEvent * sj10 = new CCreditChangeEvent("sj10", "参加结构竞赛，未完成作品，扣6学分", -6);
static CEvent * sj11 = new CCreditChangeEvent("sj11", "在宿舍睡过头，上课迟到，扣3学分", -3);
static CEvent * sj12 = new CCreditChangeEvent("sj12", "每天坚持跑操，达到满勤，加3学分", 3);
static CEvent * sj13 = new CCreditChangeEvent("sj13", "积极参加体育锻炼，校运会获长跑冠军，奖3学分", 3);
static CEvent * sj14 = new CCreditChangeEvent("sj14", "周末与同学一起打球，筋疲力尽的感觉很爽", 0);
static CEvent * sj15 = new CCreditChangeEvent("sj15", "体育课选到健身健美，测试时一口气做100个俯卧撑，得满分，加5学分", 5);
static CEvent * sj16 = new CCreditChangeEvent("sj16", "与女朋友一起到玫瑰园拍照，心里美滋滋", 0);
static CEvent * sj17 = new CCreditChangeEvent("sj17", "周末去教学楼自习，加5学分", 5);
static CEvent * sj18 = new CCreditChangeEvent("sj18", "圆满完成国奖答辩，奖25学分", 25);
static CEvent * sj19 = new CCreditChangeEvent("sj19", "上高数课睡觉被发现，扣5学分", -5);
static CEvent * sj20 = new CCreditChangeEvent("sj20", "在橘园吃晚饭后散散步，舒服~~~", 0);
static CEvent * sj21 = new CCreditChangeEvent("sj21", "在橘园田径场踢足球班赛夺冠，奖3学分", 3);
static CEvent * sj22 = new CCreditChangeEvent("sj22", "软件短学期实训获一等奖奖15学分", 15);
static CEvent * sj23 = new CCreditChangeEvent("sj23", "参加程序设计竞赛得奖，奖15学分", 15);
static CEvent * sj24 = new CCreditChangeEvent("sj24", "在金智楼制作新型机器人，奖10学分", 10);
static CEvent * sj25 = new CCreditChangeEvent("sj25", "找错金智楼与计算机楼，迷糊QAQ", 0);
static CEvent * sj26 = new CCreditChangeEvent("sj26", "物理必修实验不及格，扣5学分", -5);
static CEvent * sj27 = new CCreditChangeEvent("sj27", "物理实验圆满完成，加3学分", 3);
static CEvent * sj28 = new CCreditChangeEvent("sj28", "迎新晚会在焦标表演节目，演出很完美，奖20学分", 20);
static CEvent * sj29 = new CCreditChangeEvent("sj29", "担任学团联干事，办事得力，奖励5学分", 5);
static CEvent * sj30 = new CCreditChangeEvent("sj30", "在树林中捡到珍贵叶子样本，加5学分", 5);
static CEvent * sj31 = new CCreditChangeEvent("sj31", "拉练时把鞋子跑丢，扣2学分", -2);
static CEvent * sj32 = new CCreditChangeEvent("sj32", "给路人指路，加3学分", 3);
static CEvent * sj33 = new CCreditChangeEvent("sj33", "吃到喜欢吃的菜", 0);
static CEvent * sj34 = new CCreditChangeEvent("sj34", "挂掉高数，扣10学分", -10);
//疲劳值事件实例化
static CEvent * sj101 = new CFatigueValueChangeEvent("sj101", "在工培中心操纵机器时不小心受伤，住院两天", 2);
static CEvent * sj102 = new CFatigueValueChangeEvent("sj102", "在路上骑自行车不小心摔倒，第二天不能上课", 1);
static CEvent * sj103 = new CFatigueValueChangeEvent("sj103", "被林中的野猫抓伤，去医院包扎，耽误一天课", 1);
static CEvent * sj104 = new CFatigueValueChangeEvent("sj104", "被疯狗咬伤，住院三天", 3);
static CEvent * sj105 = new CFatigueValueChangeEvent("sj105", "偶遇漂亮小姐姐，停留一回合", 1);
static CEvent * sj106 = new CFatigueValueChangeEvent("sj106", "在化学楼做实验时，出现小型事故，住院三天", 3);
static CEvent * sj107 = new CFatigueValueChangeEvent("sj107", "去校医院检查，请假一天", 1);
static CEvent * sj108 = new CFatigueValueChangeEvent("sj108", "在宿舍睡过头，翘一天课", 1);
static CEvent * sj109 = new CFatigueValueChangeEvent("sj109", "在桃园田径场锻炼时受伤，休息一天", 1);
static CEvent * sj110 = new CFatigueValueChangeEvent("sj110", "在梅园体育场踢球时，扭伤脚踝，休养两天", 2);
static CEvent * sj111 = new CFatigueValueChangeEvent("sj111", "在食堂吃饭吃坏肚子，请假一天", 1);
static CEvent * sj112 = new CFatigueValueChangeEvent("sj112", "偷偷跑去玫瑰园摘花被发现，停课一天", 1);
static CEvent * sj113 = new CFatigueValueChangeEvent("sj113", "在菜鸟取快递时快递太多，体力不支，停留一回合", 1);
static CEvent * sj114 = new CFatigueValueChangeEvent("sj114", "到行政楼办事，请假一天", 1);
static CEvent * sj115 = new CFatigueValueChangeEvent("sj115", "翘课去南门外理发，停留一回合", 1);
static CEvent * sj116 = new CFatigueValueChangeEvent("sj116", "请假一天去大活开会", 1);
//房产事件实例化
static CEvent * sj201 = new CHouseEvent("sj201", "图书馆一号", Lib1);
static CEvent * sj202 = new CHouseEvent("sj202", "纪忠楼树林", Jzl);
static CEvent * sj203 = new CHouseEvent("sj203", "西门小树林一号", Xmwoods1);
static CEvent * sj204 = new CHouseEvent("sj204", "西门小树林二号", Xmwoods2);
static CEvent * sj205 = new CHouseEvent("sj205", "情人坡一号", Qrp1);
static CEvent * sj206 = new CHouseEvent("sj206", "情人坡二号", Qrp2);
static CEvent * sj207 = new CHouseEvent("sj207", "九龙湖宾馆一号", Jlh1);
static CEvent * sj208 = new CHouseEvent("sj208", "九龙湖宾馆二号", Jlh2);
static CEvent * sj209 = new CHouseEvent("sj209", "北门小树林一号", Bmwoods1);
static CEvent * sj210 = new CHouseEvent("sj210", "北门小树林二号", Bmwoods2);
static CEvent * sj211 = new CHouseEvent("sj211", "文科楼一号", Wkl1);
static CEvent * sj212 = new CHouseEvent("sj212", "文科楼二号", Wkl2);
static CEvent * sj213 = new CHouseEvent("sj213", "图书馆二号", Lib2);
static CEvent * sj214 = new CHouseEvent("sj214", "图书馆三号", Lib3);
static CEvent * sj215 = new CHouseEvent("sj215", "北门花池", Bmhc);
static CEvent * sj216 = new CHouseEvent("sj216", "桃56", T56);
static CEvent * sj217 = new CHouseEvent("sj217", "桃34", T34);
static CEvent * sj218 = new CHouseEvent("sj218", "桃12", T12);
static CEvent * sj219 = new CHouseEvent("sj219", "梅58", M58);
static CEvent * sj220 = new CHouseEvent("sj220", "梅14", M14);
static CEvent * sj221 = new CHouseEvent("sj221", "玫瑰园", Mgy);
static CEvent * sj222 = new CHouseEvent("sj222", "梅园小花池", Myhc);
static CEvent * sj223 = new CHouseEvent("sj223", "学区房一号", Xqf1);
static CEvent * sj224 = new CHouseEvent("sj224", "学区房二号", Xqf2);
static CEvent * sj225 = new CHouseEvent("sj225", "图书馆四号", Lib4);
static CEvent * sj226 = new CHouseEvent("sj226", "橘园宿舍区", Jydom);
static CEvent * sj227 = new CHouseEvent("sj227", "行政楼小树林", Xzlwoods);
static CEvent * sj228 = new CHouseEvent("sj228", "南门小树林一号", Nmwoods1);
static CEvent * sj229 = new CHouseEvent("sj229", "中央大道花园", Zyddhy);
static CEvent * sj230 = new CHouseEvent("sj230", "南门小树林二号", Nmwoods2);

static CEvent * sj[] = {sj01, sj02, sj03, sj04, sj05, sj06, sj07, sj08, sj09, sj10, sj11, sj12, sj13, sj14, sj15,
                        sj16, sj17, sj18, sj19, sj20, sj21, sj22, sj23, sj24, sj25, sj26, sj27, sj28, sj29, sj30,
                        sj31, sj32, sj33, sj34,
                        sj101, sj102, sj103, sj104, sj105, sj106, sj107, sj108, sj109, sj110, sj111, sj112,
                        sj113, sj114, sj115, sj116,
                        sj201, sj202, sj203, sj204, sj205, sj206, sj207, sj208, sj209, sj210, sj211, sj212,
                        sj213, sj214, sj215, sj216, sj217, sj218, sj219, sj220, sj221, sj222, sj223, sj224,
                        sj225, sj226, sj227, sj228, sj229, sj230};


//每个点包含的事件
static CEvent * events00[1] = {sj01};
static CEvent * events01[1] = {sj02};
static CEvent * events02[1] = {sj201};
static CEvent * events03[1] = {sj202};
static CEvent * events04[1] = {sj101};
static CEvent * events05[1] = {sj03};
static CEvent * events06[1] = {sj102};
static CEvent * events07[1] = {sj203};
static CEvent * events08[1] = {sj204};
static CEvent * events09[1] = {sj04};
static CEvent * events10[1] = {sj04};
static CEvent * events11[1] = {sj205};
static CEvent * events12[1] = {sj206};
static CEvent * events13[1] = {sj207};
static CEvent * events14[1] = {sj208};
static CEvent * events15[2] = {sj104, sj22};
static CEvent * events16[1] = {sj13};
static CEvent * events17[1] = {sj209};
static CEvent * events18[2] = {sj05, sj15};
static CEvent * events19[1] = {sj211};
static CEvent * events20[1] = {sj212};
static CEvent * events21[2] = {sj06, sj105};
static CEvent * events22[1] = {sj05};
static CEvent * events23[1] = {sj102};
static CEvent * events24[1] = {sj213};
static CEvent * events25[1] = {sj214};
static CEvent * events26[2] = {sj07,sj106};
static CEvent * events27[1] = {sj08};
static CEvent * events28[1] = {sj11};
static CEvent * events29[1] = {sj30};
static CEvent * events30[2] = {sj13, sj14};
static CEvent * events31[1] = {sj31};
static CEvent * events32[1] = {sj215};
static CEvent * events33[1] = {sj107};
static CEvent * events34[1] = {sj16};
static CEvent * events35[1] = {sj216};
static CEvent * events36[1] = {sj12};
static CEvent * events37[2] = {sj13, sj109};
static CEvent * events38[1] = {sj217};
static CEvent * events39[1] = {sj218};
static CEvent * events40[1] = {sj14};
static CEvent * events41[1] = {sj15};
static CEvent * events42[1] = {sj110};
static CEvent * events43[1] = {sj32};
static CEvent * events44[1] = {sj219};
static CEvent * events45[1] = {sj220};
static CEvent * events46[1] = {sj33};
static CEvent * events47[1] = {sj222};
static CEvent * events48[1] = {sj16};
static CEvent * events49[2] = {sj17, sj113};
static CEvent * events50[1] = {sj17};
static CEvent * events51[2] = {sj19, sj18};
static CEvent * events52[1] = {sj223};
static CEvent * events53[1] = {sj18};
static CEvent * events54[1] = {sj224};
static CEvent * events55[1] = {sj225};
static CEvent * events56[1] = {sj20};
static CEvent * events57[1] = {sj111};
static CEvent * events58[1] = {sj226};
static CEvent * events59[1] = {sj21};
static CEvent * events60[1] = {sj227};
static CEvent * events61[1] = {sj114};
static CEvent * events62[1] = {sj23};
static CEvent * events63[1] = {sj22};
static CEvent * events64[1] = {sj229};
static CEvent * events65[1] = {sj24};
static CEvent * events66[1] = {sj25};
static CEvent * events67[2] = {sj31, sj32};
static CEvent * events68[1] = {sj228};
static CEvent * events69[1] = {sj102};
static CEvent * events70[2] = {sj26, sj27};
static CEvent * events71[1] = {sj34};
static CEvent * events72[1] = {sj25};
static CEvent * events73[2] = {sj116, sj29};
static CEvent * events74[1] = {sj33};
static CEvent * events75[1] = {sj32};
static CEvent * events76[1] = {sj103};
static CEvent * events77[1] = {sj25};
static CEvent * events78[1] = {sj25};
static CEvent * events79[1] = {sj230};


//坐标点实例化
static CPoint p55(208,93, 1, events55, false, nullptr, nullptr);
static CPoint p54(430,217, 1, events54, false, &p55, nullptr);
static CPoint p53(610,303, 1, events53, false, &p54, nullptr);
static CPoint p52(780,405, 1, events52, false, &p53, nullptr);
static CPoint p51(918,497, 2, events51, false, &p52, nullptr);
static CPoint p50(1064,581, 1, events50, false, &p51, nullptr);
static CPoint p71(1271,390, 1, events50, false, &p50, nullptr);
static CPoint p72(1337,237, 1, events50, false, &p71, nullptr);
static CPoint p73(1430,15, 2, events50, false, &p72, nullptr);
static CPoint p74(1515,-143, 1, events50, false, &p73, nullptr);
static CPoint p75(1593,-285, 1, events50, false, &p74, nullptr);
static CPoint p76(1669,-428, 1, events50, false, &p75, nullptr);
static CPoint p49(894,783, 2, events49, false, &p50, nullptr);
static CPoint p48(714,867, 1, events48, false, &p49, nullptr);
static CPoint p47(502,993, 1, events47, false, &p48, nullptr);
static CPoint p46(782,1071, 1, events46, false, &p47, nullptr);
static CPoint p45(986,1223, 1, events45, false, &p46, nullptr);
static CPoint p44(1298,1423, 1, events44, false, &p45, nullptr);
static CPoint p43(1422,1273, 1, events43, false, &p44, nullptr);
static CPoint p42(1570,1151, 1, events42, false, &p43, nullptr);
static CPoint p41(1842,955, 1, events41, false, &p42, nullptr);
static CPoint p40(2018,783, 1, events40, false, &p41, nullptr);
static CPoint p39(2174,595, 1, events39, false, &p40, nullptr);
static CPoint p38(2354,357, 1, events38, false, &p39, nullptr);
static CPoint p37(2530,39, 2, events37, false, &p38, nullptr);
static CPoint p36(2676,-201, 1, events36, false, &p37, nullptr);
static CPoint p35(2488,-305, 1, events35, false, &p36, nullptr);
static CPoint p34(2228, -401, 1, events34, false, &p35, nullptr);
static CPoint p33(1976, -483, 1, events33, false, &p34, nullptr);
static CPoint p32(1714, -575 , 1, events32, true, &p33, &p76);
static CPoint p31(1480, -609, 1, events31, false, &p32, nullptr);
static CPoint p30(1246, -693, 2, events30, false, &p31, nullptr);
static CPoint p29(1042, -763, 1, events29, false, &p30, nullptr);
static CPoint p28(842,- 829, 1, events28, false, &p29, nullptr);
static CPoint p27(698, -635, 1, events27, false, &p28, nullptr);
static CPoint p26(516, -413, 2, events26, false, &p27, nullptr);
static CPoint p25(310, -527, 1, events25, false, &p26, nullptr);
static CPoint p24(140, -575, 1, events24, false, &p25, nullptr);
static CPoint p23(-60, -679, 1, events23, false, &p24, nullptr);
static CPoint p22(-256, -799, 1, events22, false, &p23, nullptr);
static CPoint p21(-56, -1035, 2, events21, false, &p22, nullptr);
static CPoint p20(128, -923, 1, events20, false, &p21, nullptr);
static CPoint p19(292, -819, 1, events19, false, &p20, nullptr);
static CPoint p78(446, -733, 1, events18, false, &p19, nullptr);
static CPoint p18(544, -821, 2, events17, false, &p78, nullptr);
static CPoint p77(722, -898, 1, events17, false, &p28, nullptr);
static CPoint p17(624, -937, 1, events16, true, &p77, &p18);
static CPoint p16(422, -1037, 1, events15, false, &p17, nullptr);
static CPoint p15(248, -1115, 2, events14, false, &p16, nullptr);
static CPoint p14(62, -1177, 1, events13, false, &p15, nullptr);
static CPoint p13(-186, -1243, 1, events12, false, &p14, nullptr);
static CPoint p12(-306, -1173, 1, events11, false, &p13, nullptr);
static CPoint p11(-414, -1095, 1, events10, false, &p12, nullptr);
static CPoint p10(-508, -1015, 1, events09, false, &p11, nullptr);
static CPoint p9(-638, -887, 1, events08, false, &p10, nullptr);
static CPoint p8(-714, -769, 1, events07, false, &p9, nullptr);
static CPoint p7(-826, -611, 1, events06, false, &p8, nullptr);
static CPoint p6(-954, -531, 1, events05, false, &p7, nullptr);
static CPoint p56(-1084, -363, 1, events05, false, &p6, nullptr);
static CPoint p57(-1194, -270, 1, events05, false, &p56, nullptr);
static CPoint p58(-1271, 55, 1, events05, false, &p57, nullptr);
static CPoint p59(-1116, 272, 1, events05, false, &p58, nullptr);
static CPoint p60(-855, 396, 1, events05, false, &p59, nullptr);
static CPoint p61(-570, 556, 1, events05, false, &p60, nullptr);
static CPoint p62(-403, 415, 1, events05, false, &p61, nullptr);
static CPoint p63(-244, 214, 1, events05, false, &p62, nullptr);
static CPoint p64(-148, 264, 1, events05, false, &p63, nullptr);
static CPoint p65(-7, 332, 1, events05, false, &p64, nullptr);
static CPoint p66(-118, 491, 1, events05, false, &p65, nullptr);
static CPoint p79(-406, 649, 1, events05, false, &p61, nullptr);
static CPoint p67(-265, 714, 2, events05, true, &p79, &p66);
static CPoint p68(-92,773, 1, events05, false, &p67, nullptr);
static CPoint p69(86, 843, 1, events05, false, &p68, nullptr);
static CPoint p70(283, 922, 2, events05, false, &p69, nullptr);
static CPoint p5(-801, -484, 1, events04, false, &p6, nullptr);
static CPoint p4(-692, -388, 1, events03, false, &p5, nullptr);
static CPoint p3(-510, -276, 1, events02, false, &p4, nullptr);
static CPoint p2(-370, -199, 1, events01, false, &p3, nullptr);
static CPoint p1(-185, -102, 1, events00, false, &p2, nullptr);
static CPoint p0(0, 0, 1, events00, false, &p1, nullptr);

#endif

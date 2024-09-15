//
// Created by andreas on 15.09.24.
//
#include "./../xor_queries_for_subarrays.h"
#include "gtest/gtest.h"

TEST(TestXORQueriesForSubarrays, simple1) {
    std::vector<int> input_array{1, 3, 4, 8};
    std::vector<std::vector<int>> queries{{0, 1},
                                          {1, 2},
                                          {0, 3},
                                          {3, 3}};
    std::vector<int> expected_result{2, 7, 14, 8};
    EXPECT_EQ(expected_result, xor_queries(input_array, queries));
}

TEST(TestXORQueriesForSubarrays, simple2) {
    std::vector<int> input_array{4, 8, 2, 10};
    std::vector<std::vector<int>> queries{{2, 3},
                                          {1, 3},
                                          {0, 0},
                                          {0, 3}};
    std::vector<int> expected_result{8, 0, 4, 4};
    EXPECT_EQ(expected_result, xor_queries(input_array, queries));
}


TEST(TestXORQueriesForSubarrays, complex1) {
    std::vector<int> input_array{443360004, 276940131, 551676026, 308461253, 794053327, 451780969, 742299782, 293856400,
                                 465469967, 360673537, 834294919, 981368471, 521617456, 231353007, 768224767, 890798755,
                                 527611542, 431541765, 768992353, 456471917, 98115561, 69193206, 139017490, 221340730,
                                 160635367, 246132092, 784009204, 28063369, 110879962, 271896932, 167195373, 515167426,
                                 831831846, 106249291, 428562467, 697567471, 776858211, 201256789, 895889943, 3216942,
                                 95736986, 459224380, 657013980, 54623841, 590124178, 234373334, 573900167, 452989374,
                                 372269019, 50503221, 699639249, 994326959, 110777782, 788685815, 593600836, 729143551,
                                 450573455, 896477150, 721174573, 795772539, 127395854, 284900527, 735034712, 299309165,
                                 192244583, 515087841, 864491605, 851780960, 756089412, 921106758, 51190776, 844415960,
                                 230016784, 726715803, 691781604, 93622512, 930286848, 418455523, 132916696, 718012902,
                                 480277114, 315946145, 732248290, 545265852, 534681953, 971820494, 422069342, 124722668,
                                 650807021, 916843078, 514527209, 113633750, 160130902, 414855656, 658886615, 972154472,
                                 754183621, 216036924, 179447414, 559143144, 276606141, 447325175, 797980285, 953426136,
                                 576294005, 309873901, 933007522, 528792662, 680389734, 961004463, 869948324, 584969901,
                                 980369451, 230451772, 846872697, 815681197, 669538948, 361946875, 924543260, 521811016,
                                 110444466, 9193275, 813655937, 783061093, 705751561, 372458055, 994083976, 950433240,
                                 761068935, 287262105, 60600678, 580396084, 671573837, 472716167, 321976731, 815888327,
                                 970869404, 904504727, 108188767, 245414606, 545475655, 294811562, 290272852, 758342564,
                                 264515593, 441998361, 159275467, 139802838, 275217377, 209713152, 437783727, 602207362,
                                 676485310, 642628518, 970121198, 62738626, 572068117, 895979413, 653888119, 546927199,
                                 159831569, 444316431, 290084468, 300423609, 515553868, 746704591, 328347081, 286750538,
                                 527557772, 230210580, 535537489, 394798113, 643178559, 505248208, 259483159, 363348839,
                                 189149068, 650399949, 814880683, 194565956, 793717384, 944796481, 623357606, 745360831,
                                 484379578, 574197634, 160448754, 62451269, 541108369, 350046965, 567452685, 740997152,
                                 145027464, 692632493, 817555809, 871829153, 957250012, 228901141, 338622061, 668455470,
                                 530139281, 515833047, 354379485, 127138644, 137355481, 952682491, 150449579, 749846261,
                                 275381976, 241621799, 94520165, 682108071, 578559507, 890161014, 754757225, 53720388,
                                 604594598, 184773425, 735262702, 124701677, 242931949, 604796198, 214108785, 540110156,
                                 609428853, 708567113, 949494425, 330565560, 453403106, 351801804, 4549064, 830849806,
                                 21530244, 882319385, 327818305, 882839191, 660753052, 236509325, 90801442, 797844568,
                                 241066146, 300833006, 730885919, 671789201, 924730899, 366224143, 288916292, 645468070,
                                 771768371, 556659799, 407245081, 24830042, 130627521, 354157001, 372613361, 149723829,
                                 121762948, 269317728, 964874768, 826760790, 153844704, 731435700, 616336618, 44048037,
                                 372590210, 83080911, 98591087, 778386822, 110820573, 322107696, 340397622, 267310403,
                                 289199074, 568682633, 53436389, 388433447, 33468510, 84093035, 149287458, 994029194,
                                 428774351, 399493373, 773148979, 685453290, 742280129, 259911017, 100782778, 729762391,
                                 353069493, 293811407, 8550044, 553232607, 953689010, 345559843, 120486825, 378346370,
                                 991420472, 862818986, 849314771, 688475703, 777563777, 905513947, 135184015, 650859744,
                                 995610677, 934568762, 291069742, 435040447, 97788900, 729073588, 619166793, 666404079,
                                 778864729, 566649759, 510656146, 606062809, 449598339, 575270048, 422808094, 323298518,
                                 964563097, 235570933, 679388031, 324990992, 589616415, 142940730, 57916619, 644343256,
                                 546027908, 117970379, 188062365, 258322413, 230879424, 963395373, 466661374, 294735558,
                                 586216675, 21459925, 268877982, 578567465, 290913574, 569240302, 281046426, 508131224,
                                 135370114, 433026639, 761146345, 111404496, 799847211, 401018583, 74168486, 702679478,
                                 584329161, 389921238, 584923775, 596449657, 906042794, 863783175, 776490415, 544768135,
                                 735072104, 623653735, 32656421, 664695226, 330849879, 478338003, 732734655, 141960654,
                                 167259747, 79829370, 980834214, 622000711, 152392458, 726513532, 943949458, 887816698,
                                 232216382, 519767796, 903650113, 860061395, 910779686, 823969554, 360202491, 392013627,
                                 954118794, 313901093, 171549365, 167079141, 911724393, 853749040, 409884352, 894566731,
                                 472143178, 435552705, 126550974, 645324489, 155846710, 289648107, 317067831, 716056198,
                                 737612274, 858336267, 685983660, 648200777, 8788372, 576899221, 10413552, 987500136,
                                 875342872, 690346551, 142353885, 407491837, 802072899, 603350312, 947912245, 108601573,
                                 493415303, 32605459, 836679219, 463806961, 642697721, 729338392, 453418872, 296420156,
                                 397439221, 438549348, 436082850, 650450382, 496055524, 57202840, 106500870, 505478856,
                                 836594936, 40173229, 693726354, 756056910, 748789644, 633763, 872079882, 45167558,
                                 893101022, 119320217, 630706629, 149867407, 569559877, 545544989, 819482892, 382561755,
                                 591663081, 290880211, 840660724, 610125852, 976031232, 703153082, 382700935, 861234324,
                                 508861218, 880155153, 748905132, 263252976, 995933189, 867890545, 667644300, 257495774,
                                 113323172, 603825757, 384095709, 936299475, 170359020, 124987008, 834141098, 43570857,
                                 983914372, 755972607, 336831257, 453542736, 944637829, 780907990, 371789652, 272183685,
                                 706044696, 671919110, 964609638, 829004635, 983100055, 59772213, 662447541, 466940973,
                                 445533371, 404052551, 385198676, 315606857, 809501435, 876318874, 366399341, 473541832,
                                 857051955, 750803557, 255614896, 681752116, 654602166, 557267482, 155019841, 60163072,
                                 366679801, 722666101, 121871352, 957115299, 550876168, 184897730, 583078229, 690141561,
                                 672060099, 523384014, 960372894, 366129407, 813332720, 762814885, 130440478, 625756330,
                                 23262277, 515670928, 963474721, 224641983, 411499359, 678178027, 895337853, 187594927,
                                 426538125, 769434367, 244603134, 107048296, 266667966, 360358667, 353313127, 705035530,
                                 263251732, 842375969, 726705803, 495322930, 797775219, 505911683, 396801146, 528952218,
                                 699466002, 830169174, 712081760, 776583562, 208056913, 463847023, 473095364, 428270474,
                                 581993758, 129289525, 613566838, 524284188, 995112724, 286105712, 901671668, 134448394,
                                 160933756, 12822972, 403856546, 445191649, 117008335, 857929537, 28157614, 700510908,
                                 80086064, 196457748, 492629724, 822569106, 404819424, 716423551, 539061334, 856707440,
                                 875038026, 309778181, 985650307, 166978687, 165666182, 563288638, 886937500, 113532223,
                                 273362132, 20172466, 498679292, 425789613, 870666508, 680535652, 756647044, 790354062,
                                 851410784, 979951140, 245206781, 577385120, 746795885, 419610140, 5716622, 584248194,
                                 863141592, 267871064, 454160823, 974148452, 170622829, 711105400, 192256397, 367730229,
                                 711250158, 256785636, 81665925, 832171051, 575910596, 598993913, 172817096, 188556985,
                                 403386819, 628517733, 23164048, 550956546, 232854850, 458944296, 253041094, 852981253,
                                 43438885, 553687907, 778059981, 204267876, 751947689, 541197455, 741541692, 656987446,
                                 701751168, 576335201, 82915215, 266197463, 427524378, 836957079, 499232979, 127875606,
                                 608825170, 691369663, 51912699, 415524471, 96298899, 601255201, 101566234, 688737029,
                                 875103070, 514240230, 48296386, 556710748, 256831579, 834679300, 13065655, 22388670,
                                 922648286, 335015743, 500824689, 298578158, 776248123, 446203129, 178990737, 638840666,
                                 143023902, 603083261, 759698841, 887687651, 341793728, 827424739, 574117163, 683439091,
                                 481772382, 538575059, 862262585, 448403391, 594659556, 179978306, 750418762, 424647778,
                                 750057023, 417781240, 867987326, 215520840, 531925308, 877159748, 298962725, 386537308,
                                 996630387, 162657274, 278585174, 608676665, 300098264, 907143709, 188073747, 838121069,
                                 774122921, 667910652, 89832977, 784946081, 387109267, 360900277, 996821742, 153235258,
                                 277528406, 273814543, 270877313, 375115618, 412598601, 299717607, 607167268, 502254988,
                                 14461351, 160022245, 139867522, 271360190, 242574810, 210994234, 75655558, 860819495,
                                 622067777, 577197243, 664030448, 213042431, 583054734, 460868355, 768917106, 936212216,
                                 257513902, 620206326, 149457252, 594760901, 494462228, 420174582, 763997030, 210278850,
                                 88658543, 671523593, 82838546, 164369176, 844165029, 716504894, 61766844, 32492142,
                                 801384323, 435281519, 410844915, 448023172, 732733704, 147590855, 634587220, 640920866,
                                 138701321, 722293560, 578212230, 586638424, 79636796, 995856842, 259006191, 912594151,
                                 409813876, 149708665, 306737086, 217337949, 710558694, 771921162, 426464656, 383177133,
                                 804295110, 900436780, 191451778, 241698580, 319804582, 761638246, 154406278, 373361904,
                                 528412375, 574841999, 313284604, 95115661, 552208953, 888363759, 320979148, 224235023,
                                 757395985, 497628602, 23516958, 311702734, 859574030, 869948798, 667942944, 636293750,
                                 110637426, 660549794, 400110957, 810405099, 476304365, 273693101, 663958913, 62543503,
                                 55903809, 889654554, 838864250, 338878449, 171693327, 872169485};
    std::vector<std::vector<int>> queries{{135, 779},
                                          {105, 220},
                                          {445, 769},
                                          {600, 662},
                                          {762, 775},
                                          {516, 775},
                                          {406, 468},
                                          {724, 751},
                                          {393, 731},
                                          {529, 597},
                                          {733, 765},
                                          {742, 742},
                                          {734, 749},
                                          {206, 782},
                                          {387, 726},
                                          {493, 772},
                                          {628, 687},
                                          {274, 312},
                                          {653, 695},
                                          {687, 772},
                                          {567, 695},
                                          {238, 658},
                                          {280, 711},
                                          {408, 547},
                                          {505, 555},
                                          {685, 791},
                                          {132, 323},
                                          {572, 576},
                                          {464, 486},
                                          {500, 609},
                                          {403, 776},
                                          {551, 761},
                                          {344, 468},
                                          {96,  174},
                                          {694, 789},
                                          {43,  475},
                                          {452, 548},
                                          {177, 786},
                                          {514, 611},
                                          {521, 718},
                                          {534, 718},
                                          {201, 439},
                                          {368, 705},
                                          {600, 793},
                                          {795, 796},
                                          {349, 375},
                                          {469, 491},
                                          {625, 670},
                                          {151, 443},
                                          {480, 502},
                                          {597, 725},
                                          {66,  645},
                                          {405, 452},
                                          {409, 671},
                                          {586, 751},
                                          {308, 509},
                                          {274, 634},
                                          {481, 506},
                                          {565, 797},
                                          {488, 496},
                                          {437, 592},
                                          {602, 793},
                                          {324, 731},
                                          {152, 762},
                                          {603, 745},
                                          {284, 351},
                                          {621, 713},
                                          {425, 625},
                                          {532, 544},
                                          {589, 737},
                                          {116, 153},
                                          {587, 722},
                                          {14,  117},
                                          {340, 512},
                                          {377, 761},
                                          {564, 572},
                                          {652, 746},
                                          {596, 614},
                                          {496, 538},
                                          {552, 666},
                                          {342, 598},
                                          {557, 557},
                                          {164, 496},
                                          {369, 478},
                                          {149, 743},
                                          {151, 754},
                                          {110, 523},
                                          {324, 767},
                                          {520, 735},
                                          {368, 542},
                                          {266, 643},
                                          {38,  766},
                                          {64,  709},
                                          {252, 523},
                                          {772, 797},
                                          {563, 635},
                                          {587, 788},
                                          {633, 654},
                                          {76,  801},
                                          {174, 447},
                                          {423, 465},
                                          {129, 418},
                                          {564, 749},
                                          {656, 723},
                                          {240, 455},
                                          {101, 384},
                                          {739, 800},
                                          {48,  803},
                                          {524, 678},
                                          {208, 764},
                                          {76,  639},
                                          {323, 496},
                                          {303, 743},
                                          {528, 596},
                                          {36,  488},
                                          {372, 781},
                                          {765, 767},
                                          {29,  352},
                                          {427, 510},
                                          {570, 580},
                                          {723, 798},
                                          {718, 802},
                                          {644, 778},
                                          {434, 528},
                                          {202, 440},
                                          {117, 718},
                                          {133, 733},
                                          {518, 580},
                                          {738, 772},
                                          {469, 569},
                                          {800, 800},
                                          {369, 602},
                                          {342, 656},
                                          {740, 785},
                                          {225, 234},
                                          {14,  514},
                                          {33,  201},
                                          {259, 299},
                                          {9,   244},
                                          {783, 785},
                                          {536, 624},
                                          {35,  575},
                                          {205, 419},
                                          {453, 600},
                                          {248, 750},
                                          {518, 708},
                                          {332, 532},
                                          {669, 687},
                                          {199, 384},
                                          {192, 496},
                                          {595, 704},
                                          {628, 749},
                                          {372, 383},
                                          {499, 509},
                                          {107, 781},
                                          {640, 787},
                                          {680, 759},
                                          {442, 804},
                                          {596, 683},
                                          {347, 384},
                                          {662, 769},
                                          {199, 725},
                                          {506, 794},
                                          {676, 804},
                                          {489, 796},
                                          {696, 790},
                                          {589, 785},
                                          {460, 769},
                                          {482, 566},
                                          {274, 582},
                                          {576, 771},
                                          {405, 715},
                                          {552, 618},
                                          {261, 578},
                                          {15,  634},
                                          {775, 776},
                                          {800, 803},
                                          {468, 650},
                                          {237, 757},
                                          {454, 561},
                                          {716, 776},
                                          {343, 699},
                                          {640, 677},
                                          {393, 616},
                                          {55,  712},
                                          {113, 477},
                                          {803, 803},
                                          {261, 316},
                                          {313, 506},
                                          {15,  347},
                                          {346, 504},
                                          {603, 804},
                                          {50,  263},
                                          {733, 743},
                                          {336, 397},
                                          {687, 792},
                                          {660, 676},
                                          {131, 432},
                                          {419, 730},
                                          {348, 467},
                                          {27,  686},
                                          {717, 805},
                                          {187, 703},
                                          {767, 803},
                                          {656, 749},
                                          {309, 459},
                                          {387, 602},
                                          {539, 775},
                                          {75,  278},
                                          {417, 535},
                                          {622, 632},
                                          {632, 693},
                                          {644, 701},
                                          {249, 653},
                                          {388, 495},
                                          {636, 674},
                                          {737, 775},
                                          {761, 784},
                                          {1,   730},
                                          {721, 760},
                                          {454, 708},
                                          {174, 323},
                                          {31,  410},
                                          {447, 730},
                                          {350, 797},
                                          {525, 775},
                                          {325, 805},
                                          {618, 646},
                                          {597, 762},
                                          {299, 713},
                                          {561, 730},
                                          {282, 721},
                                          {11,  329},
                                          {770, 775},
                                          {654, 779},
                                          {117, 630},
                                          {225, 496},
                                          {447, 637},
                                          {803, 803},
                                          {55,  159},
                                          {611, 742},
                                          {526, 787},
                                          {166, 298},
                                          {299, 771},
                                          {49,  118},
                                          {223, 226},
                                          {688, 695},
                                          {433, 799},
                                          {21,  88},
                                          {56,  65},
                                          {35,  585},
                                          {347, 517},
                                          {803, 803},
                                          {626, 628},
                                          {572, 626},
                                          {480, 582},
                                          {272, 574},
                                          {595, 735},
                                          {534, 662},
                                          {239, 426},
                                          {215, 615},
                                          {61,  305},
                                          {568, 747},
                                          {463, 481},
                                          {339, 506},
                                          {416, 477},
                                          {16,  592},
                                          {189, 706},
                                          {655, 678},
                                          {779, 784},
                                          {223, 453},
                                          {180, 491},
                                          {100, 160},
                                          {321, 770},
                                          {743, 752},
                                          {64,  517},
                                          {153, 389},
                                          {44,  337},
                                          {352, 381},
                                          {603, 625},
                                          {453, 555},
                                          {233, 422},
                                          {122, 180},
                                          {207, 262},
                                          {764, 771},
                                          {89,  314},
                                          {292, 550},
                                          {539, 755},
                                          {254, 287},
                                          {741, 773},
                                          {783, 789},
                                          {333, 512},
                                          {365, 597},
                                          {782, 803},
                                          {630, 727}};
    std::vector<int> expected_result{629945133, 528575886, 695997328, 248919080, 723272440, 161077822, 658589009, 676077759, 545387360, 862666097, 972825670, 61766844, 206246101, 397738676, 723522844, 166346867, 520220929, 499313920, 672597040, 604542251, 436210894, 168785398, 147694700, 119791462, 257251415, 846884155, 86303179, 361493747, 645100828, 600386168, 49561757, 71310334, 796095834, 535334268, 590205555, 411444863, 124561669, 596467128, 228502535, 512650771, 478115370, 900510211, 231291548, 1005181619, 741220102, 1027876824, 892802763, 464287821, 146430194, 870199555, 788722884, 833205654, 774170943, 971838608, 737811121, 312476275, 62432390, 601282927, 960429676, 941627670, 415400849, 124569395, 955560251, 1050309827, 11343647, 14985991, 247277489, 102413287, 1056739158, 522422413, 21930716, 314426125, 461304820, 361496146, 536748488, 650116630, 434346888, 798375122, 444390188, 66477958, 644897163, 286105712, 80018853, 519037806, 949255790, 1001465172, 828464671, 332264532, 101773628, 574830112, 1028807778, 786472121, 943422273, 405379220, 713331905, 938189510, 419165920, 863124851, 316529236, 676562103, 702423120, 696054039, 689483846, 881326940, 61747738, 966363220, 894901167, 563376936, 595757921, 17513252, 549741773, 200126433, 592226741, 856029152, 878034474, 702972911, 566169911, 1067583706, 49511365, 288704706, 374496594, 110128215, 315099006, 543105464, 506064138, 109432396, 295995487, 590891973, 793787029, 404027455, 55903809, 807545534, 736514770, 11459608, 427599196, 1037042955, 223782723, 488605214, 480181134, 1037060516, 400081762, 557127836, 672262916, 1026410354, 727828449, 36681909, 538545471, 344496462, 788839788, 154314090, 918268068, 56040180, 1043567282, 258837956, 482529003, 685343996, 480157282, 872442905, 551838489, 1012281861, 1001788059, 830239890, 1003543091, 248786111, 207490072, 1044161325, 313607071, 886444878, 8830346, 934902446, 176033581, 339243384, 582809518, 684279641, 447895825, 155181607, 274782672, 687308978, 1008740625, 178578309, 820570680, 937817166, 957291780, 93113106, 757055522, 56783640, 338878449, 380265211, 66050485, 663544520, 654736478, 162024083, 431592090, 48081015, 738073324, 293336616, 859326340, 573835275, 130295273, 527900738, 843475050, 670474910, 241067300, 390179022, 522944149, 504765319, 904256653, 475186288, 65159921, 191041127, 306397312, 963704846, 127656739, 1040921370, 109012481, 951679573, 893793676, 780891564, 709551687, 475627886, 718824652, 237504083, 206661091, 724634305, 403566966, 88616139, 146394410, 137899712, 419850068, 618613314, 764747, 637251995, 226925093, 605957408, 700972327, 298078649, 17961172, 748258527, 338878449, 836418573, 306505691, 772062823, 284679896, 841786151, 92835704, 381782761, 456679773, 129145107, 516633406, 311710229, 1057625426, 971654726, 338878449, 245198336, 419280928, 542635116, 1039344162, 515222588, 546237321, 205606573, 1040208892, 369320830, 399432469, 1061812456, 113653501, 405392543, 587717520, 1029425704, 1031174220, 585807241, 203950992, 609069451, 334223049, 936737190, 500623173, 734629907, 729389631, 336697480, 365727347, 2013178, 1039783525, 907459422, 340120696, 573428604, 348063149, 625052273, 996795244, 557721723, 670318683, 1029271388, 784660484, 929782470, 59990852, 32604758, 130638364};
    EXPECT_EQ(expected_result, xor_queries(input_array, queries));
}

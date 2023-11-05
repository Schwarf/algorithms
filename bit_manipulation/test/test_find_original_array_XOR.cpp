//
// Created by andreas on 05.11.23.
//
#include "gtest/gtest.h"
#include "find_original_array_XOR.h"

TEST(FindOriginalArray, simple)
{
	const std::vector<int> input{5, 2, 0, 3, 1};
	const std::vector<int> expected_result{5, 7, 2, 3, 2};
	EXPECT_EQ(find_original_array(input), expected_result);
}

TEST(FindOriginalArray, simple2)
{
	const std::vector<int> input{15};
	const std::vector<int> expected_result{15};
	EXPECT_EQ(find_original_array(input), expected_result);
}

TEST(FindOriginalArray, simple3)
{
	const std::vector<int> input{0, 0, 0, 0, 0};
	const std::vector<int> expected_result{0, 0, 0, 0, 0};
	EXPECT_EQ(find_original_array(input), expected_result);
}

TEST(FindOriginalArray, simple4)
{
	const std::vector<int> input{1, 0, 1, 0, 1};
	const std::vector<int> expected_result{1, 1, 1, 1, 1};
	EXPECT_EQ(find_original_array(input), expected_result);
}

TEST(FindOriginalArray, complex1)
{
	const std::vector<int> input
		{434888, 247145, 702509, 724912, 307216, 473171, 545738, 538552, 293569, 48694, 33775, 41975, 760759, 101038,
		 885447, 204201, 483623, 929111, 640316, 386443, 946469, 634295, 878733, 357176, 515575, 440196, 981688, 900920,
		 685861, 118727, 557253, 408610, 715915, 505561, 452858, 450461, 258184, 467032, 820124, 962868, 213440, 92033,
		 170090, 269174, 254914, 397493, 329200, 501992, 157451, 907737, 435530, 641173, 969273, 583347, 709138, 372137,
		 718282, 191956, 960124, 10618, 195227, 105254, 601774, 478630, 811494, 713583, 362334, 584631, 455706, 795447,
		 558935, 528610, 190683, 78688, 900978, 592220, 550838, 514363, 433400, 619186, 735412, 108112, 46734, 275040,
		 465879, 410620, 927239, 597933, 506334, 33448, 903208};
	const std::vector<int> expected_result
		{434888, 354209, 621892, 112541, 1032096, 231491, 1010585, 25714, 806265, 312567, 15833, 8216, 735296, 659737,
		 788585, 958318, 294030, 609392, 518251, 794807, 758958, 515218, 312634, 531381, 175823, 92787, 544060, 214400,
		 509981, 768226, 610050, 965863, 839849, 875090, 89635, 14183, 339733, 315600, 762820, 144040, 913652, 140865,
		 262123, 426780, 522420, 390007, 202053, 175384, 380899, 1031890, 752787, 1011167, 459436, 404618, 144545,
		 1015739, 1005667, 530462, 805800, 954118, 185313, 221629, 570760, 942856, 732224, 426633, 1008689, 879849,
		 925613, 710445, 304224, 38837, 718905, 252859, 822290, 308782, 93930, 1031821, 83395, 1044042, 150022, 696036,
		 69854, 296174, 207287, 88107, 550395, 473514, 960115, 473974, 871040};
	EXPECT_EQ(find_original_array(input), expected_result);
}

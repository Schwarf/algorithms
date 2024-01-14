//
// Created by andreas on 13.01.24.
//

#include "gtest/gtest.h"
#include "./../count_steps_to_make_strings_anagram.h"

TEST(TestCountStepsToMakeStringsAnagram, version1_simple1)
{
	const std::string input1{"bab"};
	const std::string input2{"aba"};
	constexpr int expected_output{1};
	EXPECT_EQ(steps_to_make_anagram1(input1, input2), expected_output);
}

TEST(TestCountStepsToMakeStringsAnagram, version1_simple2)
{
	const std::string input1{"cleancode"};
	const std::string input2{"practices"};
	constexpr int expected_output{5};
	EXPECT_EQ(steps_to_make_anagram1(input1, input2), expected_output);
}

TEST(TestCountStepsToMakeStringsAnagram, version1_simple3)
{
	const std::string input1{"managa"};
	const std::string input2{"anamag"};
	constexpr int expected_output{0};
	EXPECT_EQ(steps_to_make_anagram1(input1, input2), expected_output);
}

TEST(TestCountStepsToMakeStringsAnagram, version1_complex1)
{
	const std::string input1{"dexfhxsqawznisfsyfxwdwsllbxtwtqkwrwetkqcmismziegygvyzsrghawkxxewslkyvmaqbxrbphkfqzbujykvcfzplnvebhdswnhqqrkuedsihpuyhofscynoidpldwclxchhemzvdvzydiodjfusgaawasvarddbrmzfydcedizlefdxoiyunvifhgoiojkzrsudpyudbkogrhulw"};
	const std::string input2{"duksnbgytsuzwtfpdytlelqzyceurjpywakzyeakhmnouvjeuqyvoxzhpilzgbghzctwotopktlkztofakulthfihcydaksccdrcebpkojgsyfvlkspqwidqtpjukeifsesgjchcyfooywuqztqxeaeisfwxrfkcajjqjigtxihhvyelfqumqtjxjhlksyqmojvdceufgddtfuedezons"};
	constexpr int expected_output{43};
	EXPECT_EQ(steps_to_make_anagram1(input1, input2), expected_output);
}

TEST(TestCountStepsToMakeStringsAnagram, version1_complex2)
{
	const std::string input1{"mrcrrdkldvmkrjzgqedacbbebbxsnmpnwznawepfupqshjlpmxaemlqszgqlwhgbfmlnfhcvtnikcqlyguxfvxpboliilgditcrtpcqowsjjxxqlkjooekxlgvtxmittqpfzplemvvhqmvmntsmrujmwgawrpnkmsntretibzlnxusxgwqgumckttrigbsvutkgfkgfonaizhdpkzzrveooxxfpcznxtjreulvqiokvdxzkhsmrnadselodfabqbozldvxbcrzcvrnlbgwadrbmcbszlnqwdcnuzbqrzspqehkutqrgxjncxaveigngvtugabzacitncooeglbqagmexeksxidedqqxsjtdcytudtgzapeulbogltrogagturbcbgeotwkqzplsjmpexskgihxigaioqkctdcmcpefwkedpncxylimsaapnffkfioolaagepfqflpgcsttymkkcvipcgwwifqlysxbbzftajevpjoikxeyccq"};
	const std::string input2{"ysnyenpzmxgdiujyqyoivdqzajkqizucbsapqibaqmrajoagchbzmahchkgqnjtrpmjdpdibpqypyymzvkxclxiosixajwvnbxytddxluvhsswfqiqygktgpvkegxtwukknciiekuiwhdfuglhpxiujufkeompopkycqjemnyajqoczpenreamwpwfeoikaaivhuxqrhlnljajmdutninqneouckuxvvskyfoghwtlmafajzhswsfzooiqnefywkwswgrlihvewcoesjcigfacwpsqtuvgenswehmuthsbikcazvbgywijrjiqccpzsebbwaaxxfsbbjvmegsalnoeumehovtuexwfozhkvxbfophgcocxotcgjydgedsldrsuuxbbhoqjymidhzjccpnyyqmpwjcknxzfxxrjpmlkzcnwbgkfhuthvsndpfprynruvtyuogidryxnxijulljwxmqpdsxxttnyggvhvkvbcwnzryzqglfbbbw"};
	constexpr int expected_output{69};
	EXPECT_EQ(steps_to_make_anagram1(input1, input2), expected_output);
}


TEST(TestCountStepsToMakeStringsAnagram, version2_simple1)
{
	const std::string input1{"bab"};
	const std::string input2{"aba"};
	constexpr int expected_output{1};
	EXPECT_EQ(steps_to_make_anagram2(input1, input2), expected_output);
}

TEST(TestCountStepsToMakeStringsAnagram, version2_simple2)
{
	const std::string input1{"cleancode"};
	const std::string input2{"practices"};
	constexpr int expected_output{5};
	EXPECT_EQ(steps_to_make_anagram2(input1, input2), expected_output);
}

TEST(TestCountStepsToMakeStringsAnagram, version2_simple3)
{
	const std::string input1{"managa"};
	const std::string input2{"anamag"};
	constexpr int expected_output{0};
	EXPECT_EQ(steps_to_make_anagram2(input1, input2), expected_output);
}

TEST(TestCountStepsToMakeStringsAnagram, version2_complex1)
{
	const std::string input1{"dexfhxsqawznisfsyfxwdwsllbxtwtqkwrwetkqcmismziegygvyzsrghawkxxewslkyvmaqbxrbphkfqzbujykvcfzplnvebhdswnhqqrkuedsihpuyhofscynoidpldwclxchhemzvdvzydiodjfusgaawasvarddbrmzfydcedizlefdxoiyunvifhgoiojkzrsudpyudbkogrhulw"};
	const std::string input2{"duksnbgytsuzwtfpdytlelqzyceurjpywakzyeakhmnouvjeuqyvoxzhpilzgbghzctwotopktlkztofakulthfihcydaksccdrcebpkojgsyfvlkspqwidqtpjukeifsesgjchcyfooywuqztqxeaeisfwxrfkcajjqjigtxihhvyelfqumqtjxjhlksyqmojvdceufgddtfuedezons"};
	constexpr int expected_output{43};
	EXPECT_EQ(steps_to_make_anagram2(input1, input2), expected_output);
}

TEST(TestCountStepsToMakeStringsAnagram, version2_complex2)
{
	const std::string input1{"mrcrrdkldvmkrjzgqedacbbebbxsnmpnwznawepfupqshjlpmxaemlqszgqlwhgbfmlnfhcvtnikcqlyguxfvxpboliilgditcrtpcqowsjjxxqlkjooekxlgvtxmittqpfzplemvvhqmvmntsmrujmwgawrpnkmsntretibzlnxusxgwqgumckttrigbsvutkgfkgfonaizhdpkzzrveooxxfpcznxtjreulvqiokvdxzkhsmrnadselodfabqbozldvxbcrzcvrnlbgwadrbmcbszlnqwdcnuzbqrzspqehkutqrgxjncxaveigngvtugabzacitncooeglbqagmexeksxidedqqxsjtdcytudtgzapeulbogltrogagturbcbgeotwkqzplsjmpexskgihxigaioqkctdcmcpefwkedpncxylimsaapnffkfioolaagepfqflpgcsttymkkcvipcgwwifqlysxbbzftajevpjoikxeyccq"};
	const std::string input2{"ysnyenpzmxgdiujyqyoivdqzajkqizucbsapqibaqmrajoagchbzmahchkgqnjtrpmjdpdibpqypyymzvkxclxiosixajwvnbxytddxluvhsswfqiqygktgpvkegxtwukknciiekuiwhdfuglhpxiujufkeompopkycqjemnyajqoczpenreamwpwfeoikaaivhuxqrhlnljajmdutninqneouckuxvvskyfoghwtlmafajzhswsfzooiqnefywkwswgrlihvewcoesjcigfacwpsqtuvgenswehmuthsbikcazvbgywijrjiqccpzsebbwaaxxfsbbjvmegsalnoeumehovtuexwfozhkvxbfophgcocxotcgjydgedsldrsuuxbbhoqjymidhzjccpnyyqmpwjcknxzfxxrjpmlkzcnwbgkfhuthvsndpfprynruvtyuogidryxnxijulljwxmqpdsxxttnyggvhvkvbcwnzryzqglfbbbw"};
	constexpr int expected_output{69};
	EXPECT_EQ(steps_to_make_anagram2(input1, input2), expected_output);
}
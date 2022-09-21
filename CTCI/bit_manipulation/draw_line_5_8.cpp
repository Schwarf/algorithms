//
// Created by andreas on 21.09.22.
//

int draw_line(unsigned char *screen_array, int width, int x1, int x2, int y)
{
	constexpr int number_of_bits = 8;
	int first_full_byte = x1 / number_of_bits;
	int start_offset = x1 % number_of_bits;
	int last_full_byte = x2 / number_of_bits;
	int end_offset = x2 % number_of_bits;
	if(start_offset != 0)
		first_full_byte++;
	if(end_offset !=7)
		last_full_byte--;

	for(int byte = first_full_byte; byte <= last_full_byte; ++byte)
		screen_array[width/number_of_bits * y + byte] = static_cast<unsigned char> (0xFF);

	auto start_mask = static_cast<unsigned char>(0xFF >> start_offset);
	auto end_mask = static_cast<unsigned char>(0xFF >> (end_offset + 1));
	if((x1/number_of_bits) == (x2/number_of_bits)) // x1 and x2 are in the same byte
	{
		auto mask = static_cast<unsigned char>(start_mask & end_mask);
		screen_array[width/number_of_bits * y + x1/number_of_bits] |= mask;
	}
	else
	{
		if(start_offset != 0)
		{
			int byte_number = width/number_of_bits * y + first_full_byte - 1;
			screen_array[byte_number] |= start_mask;
		}
		if(end_offset != 7)
		{
			int byte_number = width/number_of_bits * y + last_full_byte + 1;
			screen_array[byte_number] |= end_mask;
		}
	}
}
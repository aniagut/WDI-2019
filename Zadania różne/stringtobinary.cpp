string_to_binary(int n) {
	string result = "";
	while (n > 0) {
		if (n % 2 == 1) result += "1";
		else result += "0";
		n /= 2;
	}
	return result;
}
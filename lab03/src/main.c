int main()
{
	//головний опір
	float res = 0.0f;
	//які-небудь значення трьох опорів
	float res1 = 1.0f;
	float res2 = 2.0f;
	float res3 = 3.0f;
	//Формула знаходження опору
	res = (res1 + res2 + res3) /
	      ((res1 * res2) + (res2 * res3) + (res3 * res1));

	return (int)res;
}

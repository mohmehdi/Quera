#include<iostream>
void Show(char *arr,int size)
{
	std::cout << "{";
	bool shit = false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == '1') 
		{
			std::cout << (shit? ", ":"") << i+1;
			shit = true;
		}
	}
	std::cout << "}"<<std::endl;
}
void SetZero(char *arr ,int size , int index) {

	for (int i = index; i < size; i++)
	{
		arr[i] = '0';
	}
}
void Subset(char* arr, int size, int index) {
	if (index<0 || index>=size) return;
	SetZero(arr, size, index);
	arr[index] = '1';
	Show(arr, size);

	Subset(arr, size, index + 1);

	arr[index] = '0';
	Subset(arr, size, index + 1);
}
int main() {
	int n;
	char arr[15];

	std::cin >> n;
	std::cout << "{}\n";
	Subset(arr, n, 0);

	std::cin.get();
}
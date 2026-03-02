#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void copy(string, string);
void F();
int N, K;

void print(string s)
{
	cout<<s;
}

int main()
{

	string in("C:\\Users\\Пользователь\\Desktop\\26.02.26.txt");
	string out("C:\\Users\\Пользователь\\Desktop\\26.02.26(1).txt");

	copy(in, out);
	print("hello world");


	cout << "input N ";
cin >> N;
cout << "input K ";
cin >> K;


F();


	return 0;
}
void F()
{
	for (int i = 0; i < K-1; i++) // заполняем первые К человек 0
		cout << 0 << ' ';

	cout << endl;

			//копия чтобы не изменять глобальные переменные


	
	for (int i = 0; i <K-1; i++)
	{
		int next_data = 1;
		int current_N = N;
		// для первых К*2 т.к. первые К-1 не умрут
		for (int j = 0; j < K; j++)
		{	// идея в том что идем по порядку но очередь человека определяется с шагом К нужн посчитать сколько
			// таких шагов будет до конца списка и прибавить какого по счету убили предыдущего
			cout << next_data + i << ' '; // выводим номер счета какой умрет человек
			next_data = next_data + current_N / K; // следущий в очерди умрет только после того как умрут все кратные К
			current_N--; // т.к. умер один уже надо проверять делимость меньшее количество 
		}
	}
}
void copy(string s_in, string s_out)
{
	ifstream in(s_in);
	ofstream out(s_out);

	string line;
	bool comment = false;

	while (getline(in, line))
	{
		string res;
		bool in_string = false;

		for (int i = 0; i < line.length(); i++)
		{
			if ((line[i] == '"' || line[i] == '\'') && !comment) // проверяем на наличие строки т.к в них нет коментов
			{
				res += line[i];
				in_string = !in_string; // меняем на противоположный т.к мы можем как открывать строку так и закрывать
				continue;
			}

			if (in_string)
			{
				res += line[i];
				continue;
			}

			if (!in_string && i + 1 < line.length()) // проверяем выход за границу
			{
				if (line[i] == '/'  && line[i + 1] == '*') // начало комента /* 
				{
					comment = true; 
				}
				if (line[i + 1] == '/' && line[i] == '*') // конец комента */
				{
					comment = false;
					i+=2;
				}
				if (line[i] == '/' && line[i + 1] == '/')
				{
					break;					// завершаем цикл т.к. нам эта строка уже не нужна 
				}
			}

			if (!comment)
				res += line[i];	// копируем
		}
		out << res << '\n'; // направляем в файл

	}

	in.close();
	out.close();
}

/*
вмуркнтгндбтеикеземшекеп
ннси
исеи
е
н
и
ени
г
тттгтгтгтгтгтг



гтгттггтг "GRFEFFETVTVRTVTRVTR/VT////TVRTV"
*/
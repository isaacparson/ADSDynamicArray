#include <iostream>
#include <windows.h>

using namespace std;

struct DynamicArray
{
	int Length;
	int Capacity;
	int* Array;
};

DynamicArray* arr = new DynamicArray();

void Init() // Создание массива
{
	arr->Capacity = 10;
	arr->Length = 0;
	arr->Array = new int[arr->Capacity];

	for (int i = 0; i < arr->Capacity; i++)
	{
		arr->Length++;
		arr->Array[i] = 1 + rand() % 100;
	}
}

void Resize(int* array) // Изменение объема массива
{
	int* buffArr = new int[arr->Capacity];

	for (int i = 0; i < arr->Capacity; i++)
	{
		buffArr[i] = arr->Array[i];
	}

	arr->Capacity *= 2;
	arr->Array = new int[arr->Capacity];

	for (int i = 0; i < arr->Length; i++)
	{
		arr->Array[i] = buffArr[i];
	}

	delete[] buffArr;
}

void AddElementBeforeAfter(int* array, int newElement, int index, bool bOrA) // Добавить элемент перед/после какого-то элемента
{
	int* buffArr = new int[arr->Capacity];

	for (int i = 0; i < arr->Length; i++)
	{
		buffArr[i] = arr->Array[i];
	}

	arr->Array = new int[arr->Capacity];

	int helpIndex = 0;

	if (bOrA == 1)
	{
		for (int i = 0; i < arr->Capacity + 1; i++)
		{
			if (i == index)
			{
				arr->Array[helpIndex] = newElement;
				helpIndex++;
			}
			arr->Array[helpIndex] = buffArr[i];
			helpIndex++;
		}
	}
	else
	{
		for (int i = 0; i < arr->Length; i++)
		{
			if (i == index - 1)
			{
				arr->Array[helpIndex] = newElement;
				helpIndex++;
			}
			arr->Array[helpIndex] = buffArr[i];
			helpIndex++;
		}
	}

	arr->Length++;
}

void AddElementTop(int* array, int newElement) // Добавить элемент в начало массива
{
	int* buffArray = new int[arr->Capacity];
	for (int i = 0; i < arr->Length; i++)
	{
		buffArray[i] = arr->Array[i];
	}
	arr->Array = new int[arr->Capacity];
	arr->Array[0] = newElement;
	arr->Length++;
	for (int i = 0; i < arr->Length; i++)
	{
		arr->Array[i + 1] = buffArray[i];
	}
}

void AddElementEnd(int* array, int newElement) // Добавить элемент в конец массива
{
	arr->Array[arr->Length] = newElement;
	arr->Length++;
}

void DeleteElement(int* array, int index) // Удалить эелемент
{
	int* helpArr = new int[arr->Capacity];

	for (int i = 0; i < arr->Length; i++)
	{
		helpArr[i] = arr->Array[i];
	}

	arr->Array = new int[arr->Capacity];

	int helpIndex = 0;

	for (int i = 0; i < arr->Length; i++)
	{
		if (i == index - 1)
		{
			continue;
		}
		else
		{
			arr->Array[helpIndex] = helpArr[i];
			helpIndex++;
		}
	}

	arr->Length--;
}

void SortedArrayUp(int* array) // Сортировка массива по возрастанию
{
	for (int i = 0; i < arr->Length; i++)
	{
		for (int k = 0; k < (arr->Length - i - 1); k++)
		{
			if (arr->Array[k] > arr->Array[k + 1])
			{
				swap(arr->Array[k], arr->Array[k + 1]);
			}
		}
	}
}

void SortedArrayDown(int* array) // Сортировка массива по убыванию
{
	for (int i = 0; i < arr->Length; i++)
	{
		for (int k = 0; k < (arr->Length - i - 1); k++)
		{
			if (arr->Array[k] < arr->Array[k + 1])
			{
				swap(arr->Array[k], arr->Array[k + 1]);
			}
		}
	}
}

void SearchBinary(int* array, int element) // Поиск элемента бинарным способом
{
	int first = 0,
		test = 0;

	int last = arr->Length - 1;

	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (arr->Array[mid] > element)
		{
			last = mid - 1;
		}
		else if (arr->Array[mid] < element)
		{
			first = mid + 1;
		}
		else if (arr->Array[mid] == element)
		{
			cout << "Индекс элемента: " << "" << mid + 1 << endl;
			test = 1;
			break;
		}
	}

	if (test == 0)
	{
		cout << "Такого элемента в массиве нет" << endl;
	}
}

void SearchLine(int* array, int element) // Поиск элемента линейным способом
{
	int index;

	for (int i = 0; i < arr->Length; i++)
	{
		if (element == arr->Array[i])
		{
			index = i;
			cout << "Индекс элемента: " << index + 1 << endl;
		}
	}
}

void Output(int* array) // Вывод элементов массива
{
	for (int i = 0; i < arr->Length; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 1, makeArray = 0;

	while (i != 0)
	{
		cout << "Введите номер функции по числу:" << endl << endl;
		cout << "1 - Создание и инициализация динамического массива" << endl;
		cout << "2 - Добавить элемент в динамический массив" << endl;
		cout << "3 - Удаление элемента из динамического массива" << endl;
		cout << "4 - Сортировка массива" << endl;
		cout << "5 - Поиск элемента" << endl;
		cout << "6 - Вывод элементов массива" << endl;
		cout << "0 - Выход из программы" << endl << endl;

		cout << "Ввод: ";
		cin >> i;
		cout << endl;

		if (i == 1)
		{
			makeArray++;
		}
		else  if (i != 1 && makeArray == 0)
		{
			while (i != 1)
			{
				cout << "Для начала работы создайте массив: ";
				cin >> i;
				if (i == 1)
				{
					makeArray++;
				}
			}
		}

		switch (i)
		{

		case 1:
		{
			cout << "\033[2J\033[1;1H";
			Init();
			cout << "Массив с десятью элементами создан" << endl << endl << endl;
			break;
		}

		case 2:
		{
			cout << "\033[2J\033[1;1H";
			int newElement, j;
			bool cycle = true;

			cout << "Введите номер способа, с помощью которого Вы хотите вставить элемент" << endl;
			cout << "1 - После элемента" << endl;
			cout << "2 - Перед элементом" << endl;
			cout << "3 - В начало массива" << endl;
			cout << "4 - В конце массива" << endl << endl;
			cout << "Ввод: ";

			while (cycle == true)
			{
				cin >> j;

				cout << endl;

				switch (j)
				{
				case 1:
				{
					cout << "\033[2J\033[1;1H";
					int index;

					cout << "Введите индекс элемента: ";
					cin >> index;
					cout << endl;

					while (index > arr->Length || index < 1)
					{
						cout << "Элемента с таким индексом не существует. Введите индекс снова: ";
						cin >> index;
					}

					if (arr->Capacity > arr->Length)
					{
						cout << "Введите новый элемент: ";
						cin >> newElement;

						AddElementBeforeAfter(arr->Array, newElement, index, 1);
					}
					else
					{
						Resize(arr->Array);

						cout << "Введите новый элемент: ";
						cin >> newElement;

						AddElementBeforeAfter(arr->Array, newElement, index, 1);
					}

					cycle = false;
					cout << endl;
					cout << "\033[2J\033[1;1H";
					break;
				}
				case 2:
				{
					cout << "\033[2J\033[1;1H";
					int index;

					cout << "Введите индекс элемента: ";
					cin >> index;
					cout << endl;

					while (index > arr->Length || index < 1)
					{
						cout << "Элемента с таким индексом не существует. Введите индекс снова: ";
						cin >> index;
					}

					if (arr->Capacity > arr->Length)
					{
						cout << "Введите новый элемент: ";
						cin >> newElement;

						AddElementBeforeAfter(arr->Array, newElement, index, 0);
					}
					else
					{
						Resize(arr->Array);

						cout << "Введите новый элемент: ";
						cin >> newElement;

						AddElementBeforeAfter(arr->Array, newElement, index, 0);
					}

					cycle = false;
					cout << endl;
					cout << "\033[2J\033[1;1H";
					break;
				}
				case 3:
				{
					cout << "\033[2J\033[1;1H";
					if (arr->Capacity > arr->Length)
					{
						cout << "Введите новый элемент: ";
						cin >> newElement;

						AddElementTop(arr->Array, newElement);
					}
					else
					{
						Resize(arr->Array);

						cout << "Введите новый элемент: ";
						cin >> newElement;

						AddElementTop(arr->Array, newElement);
					}

					cycle = false;
					cout << endl;
					cout << "\033[2J\033[1;1H";
					break;
				}
				case 4:
				{
					cout << "\033[2J\033[1;1H";
					if (arr->Capacity > arr->Length)
					{
						cout << "Введите новый элемент: ";
						cin >> newElement;

						AddElementEnd(arr->Array, newElement);
					}
					else
					{
						Resize(arr->Array);

						cout << "Введите новый элемент: ";
						cin >> newElement;

						AddElementEnd(arr->Array, newElement);
					}

					cycle = false;
					cout << endl;
					cout << "\033[2J\033[1;1H";
					break;
				}

				default:
				{
					cout << "Введите номер способа заново: ";
				}

				}
			}
			break;
		}

		case 3:
		{
			cout << "\033[2J\033[1;1H";
			int index;

			cout << "Введите индекс элемента: ";
			cin >> index;

			while (index > arr->Length || index < 1)
			{
				cout << "Элемента с таким индексом не существует. Введите индекс снова: ";
				cin >> index;
			}

			DeleteElement(arr->Array, index);

			cout << endl << "Элемент удален" << endl << endl;

			break;
		}

		case 4:
		{
			cout << "\033[2J\033[1;1H";
			int j = 0;

			cout << "Каким образом Вы хотите отсортировать массив?" << endl;
			cout << "1 - По возрастанию" << endl;
			cout << "2 - По убыванию" << endl << endl;

			cout << "Ввод: ";

			if (j != 1 && j != 2)
			{
				cin >> j;

				while (j != 1 && j != 2)
				{
					cout << "Выберите номер способа сортировки заново: ";
				}
			}

			switch (j)
			{

			case 1:
			{
				SortedArrayUp(arr->Array);
				break;
			}

			case 2:
			{
				SortedArrayDown(arr->Array);
				break;
			}
			}

			cout << "\033[2J\033[1;1H";
			cout << endl << "Массив отсортирован" << endl << endl;

			break;
		}

		case 5:
		{
			cout << "\033[2J\033[1;1H";
			int element,
				j = 0;

			cout << "Каким образом Вы хотите найти индекс элемента? Выберете номер" << endl;
			cout << "1 - Бинарным поиском" << endl;
			cout << "2 - Линейным поиском" << endl;

			cout << "Функция автоматически отсортирует исходный массив, если он не отсортирован." << endl << endl;

			cout << "Ввод: ";

			if (j != 1 && j != 2)
			{
				cin >> j;
				while (j != 1 && j != 2)
				{
					cout << "Выберите номер способа сортировки заново: ";
					cin >> j;
				}
			}

			switch (j)
			{
			case 1:
			{
				SortedArrayUp(arr->Array);

				Output(arr->Array);

				cout << endl << "Введите элемент: ";
				cin >> element;
				cout << "\033[2J\033[1;1H";
				SearchBinary(arr->Array, element);

				break;
			}
			case 2:
			{
				SortedArrayUp(arr->Array);

				Output(arr->Array);

				cout << endl << "Введите элемент: ";
				cin >> element;
				cout << "\033[2J\033[1;1H";
				SearchLine(arr->Array, element);

				break;
			}
			}
			break;
		}

		case 6:
		{
			cout << "\033[2J\033[1;1H";
			Output(arr->Array);
			cout << endl;

			break;
		}

		case 7:
		{
			cout << "1 - Создание и инициализация динамического массива" << endl;
			cout << "2 - Добавить элемент в динамический массив" << endl;
			cout << "3 - Удаление элемента из динамического массива" << endl;
			cout << "4 - Сортировка массива" << endl;
			cout << "5 - Поиск элемента" << endl;
			cout << "6 - Вывод элементов массива" << endl;
			cout << "0 - Выход из функции" << endl << endl;

			cout << "Ввод: ";

			break;
		}

		case 0:
		{
			cout << "\033[2J\033[1;1H";
			cout << "Спасибо за работу!" << endl;
			break;
		}

		default:
		{
			cout << "\033[2J\033[1;1H";
			cout << "Номер функции записан неверно. Введите номер заново: ";

			break;
		}
		}
	}
	delete[] arr;
}
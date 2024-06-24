#include"StudentClass.h"
#include<fstream>
#include<vector>
#include<chrono>
#include<cmath>
#include<unordered_map>
#include<vector>

//функции для отслеживания работы бинарного поиска

std::string printElemInBinary(Student* element) {
    return '[' + std::to_string(element->lineNumber) + ',' + std::to_string(element->key) + "] ";
}


void printBinaryStep(std::vector<Student*> data, int left, int right, int mid) {
    if (left == right) {
        std::cout << "1 element: " << printElemInBinary(data[left]) << left << '\n';
        return;
    }

    for (int i = left; i <= right; i++) {
        std::cout << printElemInBinary(data[i]) << ' ';
    }
    std::cout << "mid: " << printElemInBinary(data[mid]) << ' ' << left << ' ' << right << '\n';


}



//

void generateFile(int n, std::string path);

std::vector<Student*> readFile(std::string path, int start, int end);

void writeMatchingStudents(const std::vector<Student*>& matchingStudents, const std::string& filePath, unsigned int time);

bool compareStudents(const Student* a, const Student* b) {
    return a->key < b->key;
}

void swap(Student* one, Student* two) {
    Student temp = *one;

    return;
}

void bubbleSort(std::vector<Student*>& students) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < students.size() - 1; ++i) {
            if (students[i]->key > students[i + 1]->key) {
                std::swap(students[i], students[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}



int binarySearchLast(const std::vector<Student*>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    int steps = 0;

    while (left <= right) {
        ++steps;
        int mid = left + (right - left) / 2;
        printBinaryStep(arr, left, right, mid);
        if (arr[mid]->key == target) {
            result = mid;
            left = mid + 1;
            std::cout << "found on " + std::to_string(steps) + " step" + '\n';
        }
        else if (arr[mid]->key < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
       
    }

    std::cout << "Steps: " << steps << std::endl;

    return result;
}



int linearSearch(const std::vector<Student*>& arr, int target) {
    int temp_position = -1;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i]->key == target) {
            temp_position = i;
        }
    }

    return temp_position;
}



void search(std::string path, int countLines, std::string algorithm, int target);

Student* callBinarySearch(std::vector<Student*> data ,int countLines, int target) {
    
    Student* result = nullptr;

    bubbleSort(data);

    int index = binarySearchLast(data, target);

    if (index != -1) {
        result = data[index];
    }
    return result;



}

Student* callLinearSearch(std::vector<Student*> data, int countLines, int target) {

    Student* result = nullptr;

    int index = linearSearch(data, target);

    if (index != -1) {
        result = data[index];
    }
    return result;
}




int main()
{
    ////To Do СДЕЛАТЬ КАУНТ ШАБЛОНОВ
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    //generateFile(1000, "input.txt");
    int countLines = 0;
    
    std::cout << "Enter count linesэ\n";
    std::cin >> countLines;

    int target = 0;
    std::cout << "Enter target number\n";
    std::cin >> target;

    search("input.txt", countLines, "binary", target);
    search("input.txt", countLines, "linear", target);
}


std::vector<Student*> readFile(std::string path, int start, int end) {

    int countStudent = end - start + 1;

    std::ifstream file(path);

    std::string numberOfString = "";
    std::getline(file, numberOfString);
    std::cout << numberOfString << '\n';

    std::string parseData = "";

    for (int i = 0; i < start - 1; ++i) {
        std::getline(file, parseData);
    }

    std::vector<Student*> students(countStudent);

    int i = 0;

    while (std::getline(file, parseData) && i != countStudent) {
        Student* newStudent = new Student(i);
        newStudent->parseData(parseData);
        students[i] = newStudent;
        ++i;
    }

    file.close();
    return students;
}

void generateFile(int n, std::string path)
{
    std::ofstream outFile;
    try {
        outFile.open(path);
        outFile << n << '\n';
        for (int i = 0; i < n; i++) {
            outFile << "05" << std::to_string(rand() % 13 + 12) << ' ' << std::to_string(rand() % 700000 + 100000) << ' ';

            std::string firstNames[] = { "Alexander", "Dmitry", "Maxim", "Ivan", "Anatoly", "Vadim", "Gennady", "Sergey", "Andrey", "Nikolai", "Pavel", "Oleg", "Vladimir", "Artem", "Konstantin", "Gregory", "Yuri",
                            "Victor", "Eugene", "Igor", "Roman", "Mikhail", "Vitaly", "Stanislav", "Denis", "Alexey", "Peter", "Fedor", "Timur", "Svyatoslav", "Valery", "Alexander", "Marat", "Anton", "Arthur", "Daniel", "Eduard", "Arseny",
                            "Gleb", "Egor", "Leonid", "Ilya", "Vyacheslav", "David", "Semyon", "Ivan", "Boris", "Maxim", "Matthew", "Kirill", "Philip", "Dmitry", "Vasily", "Andrey", "Antonio", "Donato", "Ignatius", "Leon", "Luke",
                            "Mark", "Miron", "Nikita", "Oscar", "Rodion", "Rostislav", "Ruslan", "Svyatopolk", "Sergey", "Spartak", "Timofey", "Fedor", "Felix", "Khariton", "Emil", "Eric", "Yuri", "Yaroslav", "Alexey", "Andrey", "Anton",
                            "Artem", "Valery", "Vasily", "Victor", "Vitaly", "Gennady", "Gregory", "David", "Daniel", "Denis", "Dmitry", "Eugene", "Egor", "Ivan", "Ignatius", "Igor", "Ilya", "Kirill", "Konstantin", "Leonid", "Luka",
                            "Maxim", "Marat", "Mark", "Matthew", "Mikhail", "Nikita", "Nikolay", "Oleg", "Oscar", "Pavel", "Peter", "Rodion", "Roman", "Rostislav", "Ruslan", "Svyatoslav", "Semyon", "Sergey", "Spartak", "Stanislav",
                            "Timofey", "Timur", "Fedor", "Felix", "Philip", "Khariton", "Eduard", "Emil", "Eric", "Yuri" };
            std::string lastNames[] = { "Ivanov", "Smirnov", "Kuznetsov", "Popov", "Sokolov", "Lebedev", "Kozlov", "Novikov", "Morozov", "Petrov", "Volkov", "Solovyov", "Vasiliev", "Zaitsev", "Pavlov", "Semenov", "Golubev",
                            "Vinogradov", "Bogdanov", "Vorobyov", "Fedorov", "Mikhailov", "Belyaev", "Tarasov", "Belov", "Komarov", "Orlov", "Kiselyov", "Makarov", "Andreev", "Kovalev", "Ilyin", "Gusev", "Titov", "Kuzmin", "Kudryavtsev",
                            "Baranov", "Kulikov", "Alekseev", "Stepanov", "Yakovlev", "Sorokin", "Sergeev", "Romanov", "Zakharov", "Borisov", "Korolev", "Gerasimov", "Ponomarev", "Grigoriev", "Lazarev", "Medvedev", "Ershov", "Nikitin",
                            "Sobolev", "Ryabov", "Polyakov", "Tsvetkov", "Danilov", "Zhukov", "Frolov", "Shcherbakov", "Kotov", "Grishin", "Matveev", "Dorofeev", "Zhuravlev", "Ovchinnikov", "Trofimov", "Leonov", "Safonov", "Kondratiev",
                            "Kopylov", "Dyachkov", "Savin", "Timofeev", "Fomin", "Chernov", "Abramov", "Martynov", "Efimov", "Fedotov", "Shchukin", "Bykov", "Alexandrov", "Petukhov", "Polyakov", "Loginov", "Safonov", "Kolesnikov" };
            std::string middleNames[] = { "Alexandrovich", "Dmitrievich", "Maksimovich", "Ivanovich", "Anatolyevich", "Vadimovich", "Gennadievich", "Sergeevich", "Andreevich", "Nikolaevich", "Pavlovich", "Olegovich", "Vladimirovich",
                            "Artemovich", "Konstantinovich", "Grigorievich", "Yurievich", "Viktorovich", "Evgenievich", "Igorevich", "Romanovich", "Mikhailovich", "Vitalievich", "Stanislavovich", "Denisovich", "Alekseevich", "Petrovich",
                            "Fedorovich", "Timurovich", "Svyatoslavovich", "Valerievich", "Alexandrovich", "Maratovich", "Antonovich", "Arturovich", "Daniilovich", "Eduardovich", "Arsenievich", "Glebovich", "Egorovich", "Leonidovich",
                            "Ilyich", "Vyacheslavovich", "Davidovich", "Semenovich", "Ivanovich", "Borisovich", "Maksimovich", "Matveevich", "Kirillovich", "Filippovich", "Dmitrievich", "Vasilyevich", "Andreevich", "Antonievich",
                            "Donatovich", "Ignatievich", "Leonovich", "Lukyanovich", "Markovich", "Mironovich", "Nikitich", "Oskarovich", "Rodionovich", "Rostislavovich", "Ruslavovich", "Svyatopolkovich", "Sergeevich", "Spartakovich",
                            "Timofeevich", "Fedorovich", "Feliksovich", "Kharitonovich", "Emilevich", "Erikovich", "Yurievich", "Yaroslavovich", "Alekseevich", "Andreevich", "Antonovich", "Artemovich", "Valerievich", "Vasilyevich",
                            "Viktorovich", "Vitalievich", "Gennadievich", "Grigorievich", "Davidovich", "Daniilovich", "Denisovich", "Dmitrievich", "Evgenievich", "Egorovich", "Ivanovich", "Ignatievich", "Igorevich", "Ilyich", "Kirillovich",
                            "Konstantinovich", "Leonidovich", "Lukyanovich" };

            std::string cities[] = { "Moskva", "Sankt-Peterburg", "Novosibirsk", "Ekaterinburg",
                                                                "Kazan", "Chelyabinsk", "Omsk", "Samara", "Rostov-na-Donu",
                                                                "Ufa", "Krasnoyarsk", "Perm", "Voronezh", "Volgograd",
                                                                "Krasnodar", "Saratov", "Tyumen", "Tolyatti", "Izhevsk",
                                                                "Barnaul", "Ulyanovsk", "Irkutsk", "Khabarovsk", "Yaroslavl",
                                                                "Vladivostok", "Makhachkala", "Tomsk", "Orenburg", "Kemerovo",
                                                                "Novokuznetsk", "Astrakhan", "Penza", "Ryazan",
                                                                "Lipetsk", "Tula", "Kirov", "Cheboksary", "Kaliningrad",
                                                                "Kursk", "Magnitogorsk", "Nizhny Tagil", "Ulan-Ude", "Belgorod",
                                                                "Arkhangelsk", "Vladimir", "Sochi", "Smolensk", "Kaluga",
                                                                "Stavropol", "Kurgan", "Vologda", "Orel", "Yakutsk",
                                                                "Tambov", "Vladikavkaz", "Murmansk", "Podolsk", "Cherepovets" };

            std::string streets[] = { "Lenina", "Pobedy", "Gagarina", "Kirova", "Mira",
                                                        "Sovetskaya", "Sverdlova", "Komsomolskaya", "Oktyabrskaya", "Pushkina",
                                                        "Kalinina", "Stroiteley", "Zavodskaya", "Centralnaya", "Lesnaya",
                                                        "Naberezhnaya", "Sadovaya", "Pervomayskaya", "Shkolnaya", "Novaya",
                                                        "Kirovskaya", "Molodezhnaya", "Zelenaya", "Sportivnaya", "Gorkogo",
                                                        "Krasnaya", "Proletarskaya", "Zheleznodorozhnaya", "Sosnovaya", "Dachnaya",
                                                        "Nikitskaya", "Rabochaya", "Truda", "Partizanskaya", "Pionerskaya",
                                                        "Volodarskogo", "Perekopskaya", "Svetlaya", "Tsentralnaya", "Bolshaya",
                                                        "Malaya", "Komsomolskiy", "Kotovskogo", "Ordzhonikidze", "Kubanskaya",
                                                        "Strelkovaya", "Koltsevaya", "Nekrasova", "Shosseynaya", "Beregovaya",
                                                        "Kommunisticheskaya", "Bolnichnaya", "Korolenko", "Kutuzova", "Lugovaya",
                                                        "Klubnaya", "Kalinin", "Vokzalnaya", "Zvezdnaya", "Svetovaya",
                                                        "Nagornaya", "Morskaya", "Turgeneva", "Komsomolskaya", "Zheleznodorozhnaya" };



            std::string studentData = lastNames[rand() % 90] + " " + firstNames[rand() % 100] + " " + middleNames[rand() % 100] + " " + cities[rand() % 57] + ' ' + streets[rand() % 64] + ' ' + std::to_string(rand() % 40 + 1);//std::to_string(rand() % 200 + 1);
            outFile << studentData << '\n';
        }
        outFile.close();
    }
    catch (std::exception e) {
        std::cout << e.what() << '\n';
    }
}

void writeMatchingStudents(Student* result, const std::string& filePath, unsigned int time)
{
    std::ofstream outFile(filePath);
    outFile << time << "ms" << '\n';
    if (!outFile) {
        std::cerr << "Error: Could not open file \"" << filePath << "\" for writing." << std::endl;
        return;
    }
    outFile << "Matching students:" << '\n';
    outFile << "Line: " << result->lineNumber << ", " << *result;
}




void search(std::string path, int countLines, std::string algorithm, int target)
{
    Student* result = nullptr;
    std::vector<Student*> data;
    data = readFile(path, 1, 0 + countLines);
    auto start_time = std::chrono::high_resolution_clock::now();

    if (algorithm == "binary") {
        result = callBinarySearch(data, countLines, target);
    }
    else if (algorithm == "linear") {
        result = callLinearSearch(data, countLines, target);
    }
    else {
        std::cout << "Unknown algorithm. \n";
        return;
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    if (!result) {
        std::cout << "No matching students found.\n";
    }
    else {
        if (algorithm == "binary") {

            writeMatchingStudents(result, "outputbinary.txt", duration.count());
        }
        else {
            writeMatchingStudents(result, "outpulinear.txt", duration.count());
        }
    }

    data.clear();
}
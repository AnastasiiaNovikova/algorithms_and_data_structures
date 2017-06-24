/*

Submit a solution for A-Поиск числа в таблице
Time limit:	2 s
Real time limit:	5 s
Memory limit:	64M
Поиск числа в таблице
На вход задачи подаётся число N, числовой двумерный массив a размера N × N и число x. Массив a обладает следующим свойством: a[i, j] ≤ a[i + 1, j], a[i, j] ≤ a[i, j + 1]. Необходимо проверить, встречается ли элемент x в массиве a.
Input format
N
a[N, 1] a[N, 2] ... a[N, N]
a[N - 1, 1] a[N - 1, 2] ... a[N - 1, N]
...
a[1, 1] a[1, 2] ... a[1, N]
Output format
yes/no
Examples
Input	Output
2
0 2
0 1
1
yes
*/



#include<iostream>
#include<fstream>
#include<cstring>
#define maxInt 2147483647
#define minInt -2147483648


using namespace std;

struct tree{
    int key;			// ключ
    tree *left, *right; // левое и правое поддерево
    char bal;			// баланс узла
};

class bstree
{
    tree *head;
public:
    bstree() { head = NULL; }			// конструктор по умолчанию
    tree *getTree() { return head; }	// получение указателя на узел
    int insert(int b);			// добавление нового элемента
    tree* rotate_left(tree *);
    tree* rotate_right(tree *);
    tree* find(int b);			// поиск элемента
    int next(int);						// поиск следующего элемента
    int prev(int);						// поиск предыдущего элемента
    int remove(int b);			// удаление заданного элемента
    ~bstree();							// деструктор по умолчанию
};

/**
 * Функция вставки элемента в дерево
 * Вход: элемент
 */
int bstree::insert(int b)
{
    tree *temp = new tree;		// временная переменная
    temp->key = b;				// заполняем переданным значением
    temp->left = NULL;			// и нулевыми ссылками на потомков
    temp->right = NULL;
    
    if (!head) {				// если дерево пусто
        head = temp;			// назначаем новый элемент корнем
    }
    else {
        tree *t = head;			// временная переменная
        while (t) {				// пока не обошли все дерево
            if (t->key > b) {	// если текущий элемент больше нового
                !(t->left) ? t = t->left = temp : t = t->left;  // и у текущего элемента нет потомка слева,
            }								// то назначаем новый элемент этим потомком, иначе переходим к следующему узлу
            if (t->key < b) {	// если текущий элемент меньше нового
                !(t->right) ? t = t->right = temp : t = t->right;	// и отсутствует правый потом, то новый назначаем правым
            }								// потомком, иначе переходим к следующему
            if (t->key == b) {	// если текущий элемент равен новому
                if (t != temp) delete temp;		// освобождаем выделенную память
                break;							// и выходим из функции
            }
        }
    }
    return 0;
}

/**
 * Функция поиска элемента
 * Вход: искомый элемент
 * Выход: адрес узла дерева с искомым элементом
 */


/**
 * Функция поиска следующего элемента в дереве
 */
int bstree::next(int b){
    if(!head) return 0;
    
    tree *temp = head, *successor = NULL;
    while(temp){
        //temp = (temp->key > b) ? temp->left : (temp->key < b) ? temp->right : temp;
        if(temp->key > b){
            successor = temp;
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    return successor ? successor->key : maxInt;
}

/**
 * Функция поиска предыдущего элемента в дереве
 */
int bstree::prev(int b){
    if(!head) return 0;
    
    tree *temp = head, *successor = NULL;
    while(temp){
        //temp = (temp->key > b) ? temp->left : (temp->key < b) ? temp->right : temp;
        if(temp->key < b){
            successor = temp;
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }
    return successor ? successor->key : minInt;
}

/**
 * Функция удаления элемента из дерева
 * Вход: элемент для удаления
 * Выход: неиспользуется (всегда 0)
 */
int bstree::remove(int b)
{
    if (!head) return 0;	// Если дерево пусто - выходим
    tree *temp = head;		// временная переменная
    while(temp){			// пока не обошли все
        tree *t = temp;		// временная переменная для запоминания адреса родителя
        temp = (temp->key > b) ? temp->left : (temp->key < b) ? temp->right : temp;
        // переходим к следующему элементу, в зависимости от величины элемента
        
        if (temp && temp->key == b) {		// если нашли узел
            if (!temp->left && !temp->right) {	// и у него нет обоих потомков
                if (t != temp) t->left == temp ? t->left = NULL : t->right = NULL; // и если это не корень, то меняем родительскую ссылку на нуль
                else head = NULL;  // иначе присваиваем нуль корню
                delete temp;		// освобождаем память
            }else if (!temp->left || !temp->right) {	// если у найденного узла нет одного из потомков
                t = temp->left ? temp->left : temp->right; // временной переменной присваиваем адрес потомка
                temp->key = t->key;			// меняем значение элемента на дочернее
                temp->left = t->left;		// меняем ссылки на дочерние
                temp->right = t->right;
                delete t;					// освобождаем память
            }else {									// иначе (у найденного узла есть оба потомка)
                if (!temp->right->left) {			// и нет левого потомка у потомка найденного узла справа
                    t = temp->right;				// временной переменной присваиваем адрес правого потомка
                    temp->key = t->key;				// меняем значение найденного узла
                    temp->right = t->right;			// меняем ссылку на дочернюю
                    delete t;						// освобождаем память
                }else {								// иначе
                    t = temp->right->left;			// временной переменной присваиваем адрес левого потомка потомка справа
                    while (t->left) {				// пока не обошли все
                        t = t->left;				// ищем самый левый элемент
                    }
                    int temp_key = t->key;	// временной переменной присваиваем значение найденного левого элемента
                    remove(temp_key);				// рекурсивно удаляем левый элемент
                    temp->key = temp_key;			// меняем значение найденного узла
                }
            }
            break;
        }
    }
    return 0;
}


bstree::~bstree()
{
    while (head) {				// пока дерево не пусто
        remove(head->key);		// удаляем корневой элемент
    }
}


int main(){
    
    int N;
    cin>>N;
    

    bstree bst;
    int key = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
                cin>>key;
            bst.insert(key);
        }
    }

            cin>>key;
            if(bst.find(key)){
                cout<<"yes\n";
            }else{
                cout<<"no\n";
            }
    
    
    
    return 0;
    }

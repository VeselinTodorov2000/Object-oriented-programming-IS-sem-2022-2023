#include <iostream>

enum BookType {
    PAPER = 1,
    EBOOK = 2,
    AUDIO = 3
};

enum class BookTypeClass {
    PAPER = 1,
    EBOOK = 2,
    AUDIO = 3
};

//Да се напише функция която приема вид книга
//и ни отпечатва на конзолата с думи
//вида книга. Пример: PAPER -> “Paper”
void toString(const BookType &bookType) {
    switch (bookType) {
        case PAPER:
            std::cout << "PAPER" << std::endl;
            break;
        case EBOOK:
            std::cout << "EBOOK" << std::endl;
            break;
        case AUDIO:
            std::cout << "AUDIO" << std::endl;
            break;
        default:
            std::cout << "Invalid" << std::endl;
    }
}

//Да се напише функция която приема число и ни изкарва
// дали има вид книга в enum-a на който да съответства.
bool bookTypeExists(int number) {
    switch (number) {
        case PAPER:
        case EBOOK:
        case AUDIO:
            return true;
        default:
            return false;
    }
}

int main() {
    BookType bookType = PAPER;
    toString(bookType);

    std::cout << bookTypeExists(5) << std::endl;
    return 0;
}
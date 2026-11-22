// Structures - 1
// Structures - 2 : Student Records and Academic Analytics System
// Notes:
// - Sorting is done on a COPY of the array, so the stored records keep
//   their insertion order. Order: GPA high to low, ties by smaller roll first.
// - When the array is full, its size is doubled with realloc.
// - Update asks for a new name, age and GPA; if any value is invalid,
//   nothing is changed.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NAME_SIZE    50        // 49 characters + '\0'
#define LINE_SIZE    256
#define MAX_CAPACITY 100000

typedef struct {
    int roll;
    char name[NAME_SIZE];
    int age;
    float gpa;
} Student;


// Allocate space for n students. Returns NULL if n is bad or malloc fails.
Student* create_student_list(int n) {
    if (n <= 0 || n > MAX_CAPACITY){
        return NULL;
    }
     
    if ((size_t)n > SIZE_MAX / sizeof(Student)) { 
        return NULL;
           // overflow check
           }
   
    Student *studs = (Student*) malloc((size_t)n * sizeof(Student));
    return studs;
}

// Double the capacity. If realloc fails, the old array is kept unchanged.
int grow_student_list(Student **list, int *capacity) {
    if (*capacity >= MAX_CAPACITY) return 0;
    int new_capacity = *capacity * 2;
    if (new_capacity > MAX_CAPACITY) new_capacity = MAX_CAPACITY;
    if ((size_t)new_capacity > SIZE_MAX / sizeof(Student)) return 0;

    Student *temp = (Student*) realloc(*list, (size_t)new_capacity * sizeof(Student));
    if (temp == NULL) return 0;          // *list is still valid
    *list = temp;
    *capacity = new_capacity;
    return 1;
}

void free_student_list(Student *students) {
    free(students);
}

// records

// Put a student's details at index i.
void add_student(Student *studs, int i, int roll, const char *name, int age, float gpa) {
    studs[i].roll = roll;
    strcpy(studs[i].name, name);         // name length is validated before this
    studs[i].age = age;
    studs[i].gpa = gpa;
}

// Returns the index of the roll number, or -1 if not found.
int find_student(Student *students, int size, int roll) {
    for (int i = 0; i < size; i++) {
        if (students[i].roll == roll) return i;
    }
    return -1;
}

// Remove the student at index idx and shift the rest left.
void delete_student(Student *students, int *size, int idx) {
    for (int i = idx; i < *size - 1; i++) {
        students[i] = students[i + 1];
    }
    (*size)--;
}

void print_header() {
    printf("%-8s %-49s %-5s %-5s\n", "Roll", "Name", "Age", "GPA");
}

void print_student(Student *s) {
    printf("%-8d %-49s %-5d %-5.2f\n", s->roll, s->name, s->age, s->gpa);
}

void display_students(Student *students, int size) {
    print_header();
    for (int i = 0; i < size; i++) {
        print_student(&students[i]);
    }
}

// validation 

int valid_roll(int roll)    { return roll > 0; }
int valid_age(int age)      { return age >= 16 && age <= 100; }
int valid_gpa(float gpa)    { return gpa >= 0.0 && gpa <= 4.0; }

// Name must be 1..49 characters and not only spaces.
int valid_name(const char *name) {
    if (strlen(name) == 0 || strlen(name) >= NAME_SIZE) return 0;
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] != ' ') return 1;
    }
    return 0;
}

//input 

// Read one line. Returns 0 at end of input, 2 if the line was too long, else 1.
int read_line(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL) return 0;

    int len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
        return 1;
    }
    if (feof(stdin)) return 1;           // last line had no newline
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }   // throw away the rest
    return 2;
}

// Convert text to int. Returns 1 if the whole text is a number.
int parse_int(const char *text, int *value) {
    char *end;
    long v = strtol(text, &end, 10);
    if (end == text) return 0;
    while (*end == ' ') end++;
    if (*end != '\0') return 0;
    if (v < -2147483647L || v > 2147483647L) return 0;
    *value = (int)v;
    return 1;
}

int parse_float(const char *text, float *value) {
    char *end;
    double v = strtod(text, &end);
    if (end == text) return 0;
    while (*end == ' ') end++;
    if (*end != '\0') return 0;
    *value = (float)v;
    return 1;
}

int read_int(const char *prompt, int *value) {
    char buf[LINE_SIZE];
    if (read_line(prompt, buf, LINE_SIZE) != 1 || !parse_int(buf, value)) {
        printf("Error: please enter a whole number.\n");
        return 0;
    }
    return 1;
}

int read_float(const char *prompt, float *value) {
    char buf[LINE_SIZE];
    if (read_line(prompt, buf, LINE_SIZE) != 1 || !parse_float(buf, value)) {
        printf("Error: please enter a number.\n");
        return 0;
    }
    return 1;
}

// Reads a name (spaces allowed). Returns 1 if valid.
int read_name(char *name) {
    char buf[LINE_SIZE];
    int r = read_line("Name: ", buf, LINE_SIZE);
    if (r == 0) { printf("Error: no input.\n"); return 0; }
    if (r == 2 || strlen(buf) >= NAME_SIZE) {
        printf("Error: name too long (maximum %d characters).\n", NAME_SIZE - 1);
        return 0;
    }
    if (!valid_name(buf)) {
        printf("Error: name cannot be empty.\n");
        return 0;
    }
    strcpy(name, buf);
    return 1;
}

int read_age(int *age) {
    if (!read_int("Age (16-100): ", age)) return 0;
    if (!valid_age(*age)) {
        printf("Error: age must be between 16 and 100.\n");
        return 0;
    }
    return 1;
}

int read_gpa(float *gpa) {
    if (!read_float("GPA (0.00-4.00): ", gpa)) return 0;
    if (!valid_gpa(*gpa)) {
        printf("Error: GPA must be between 0.00 and 4.00.\n");
        return 0;
    }
    return 1;
}

// menu operations

void add_new_student(Student **list, int *size, int *capacity) {
    int roll, age;
    float gpa;
    char name[NAME_SIZE];

    if (!read_int("Roll number: ", &roll)) return;
    if (!valid_roll(roll)) {
        printf("Error: roll number must be positive.\n");
        return;
    }
    if (find_student(*list, *size, roll) != -1) {
        printf("Error: roll number %d already exists.\n", roll);
        return;
    }
    if (!read_name(name)) return;
    if (!read_age(&age)) return;
    if (!read_gpa(&gpa)) return;

    if (*size == *capacity) {                    // array is full: grow it
        if (!grow_student_list(list, capacity)) {
            printf("Error: cannot grow the list (out of memory or limit reached). Student not added.\n");
            return;
        }
        printf("(Capacity expanded to %d.)\n", *capacity);
    }
    add_student(*list, *size, roll, name, age, gpa);
    (*size)++;
    printf("Success: student %d added.\n", roll);
}

void search_student(Student *list, int size) {
    int roll;
    if (!read_int("Roll number to search: ", &roll)) return;
    int idx = find_student(list, size, roll);
    if (idx == -1) {
        printf("Error: no student with roll number %d.\n", roll);
        return;
    }
    print_header();
    print_student(&list[idx]);
}

void update_student(Student *list, int size) {
    int roll, age;
    float gpa;
    char name[NAME_SIZE];

    if (!read_int("Roll number to update: ", &roll)) return;
    int idx = find_student(list, size, roll);
    if (idx == -1) {
        printf("Error: no student with roll number %d.\n", roll);
        return;
    }
    // read everything first, so a bad value changes nothing
    if (!read_name(name)) { printf("Update cancelled.\n"); return; }
    if (!read_age(&age))  { printf("Update cancelled.\n"); return; }
    if (!read_gpa(&gpa))  { printf("Update cancelled.\n"); return; }

    add_student(list, idx, roll, name, age, gpa);
    printf("Success: student %d updated.\n", roll);
}

void remove_student(Student *list, int *size) {
    int roll;
    if (!read_int("Roll number to delete: ", &roll)) return;
    int idx = find_student(list, *size, roll);
    if (idx == -1) {
        printf("Error: no student with roll number %d.\n", roll);
        return;
    }
    delete_student(list, size, idx);
    printf("Success: student %d deleted.\n", roll);
}

// Highest, lowest and average GPA.
void show_summary(Student *list, int size) {
    if (size == 0) {
        printf("No students stored; GPA summary is not available.\n");
        return;
    }
    int highest = 0, lowest = 0;
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += list[i].gpa;
        if (list[i].gpa > list[highest].gpa) highest = i;
        if (list[i].gpa < list[lowest].gpa) lowest = i;
    }
    printf("Highest GPA:\n");
    print_header();
    print_student(&list[highest]);
    printf("Lowest GPA:\n");
    print_header();
    print_student(&list[lowest]);
    printf("Average GPA: %.2f\n", total / size);
}

// Sorted by GPA (high to low), ties by roll number (low to high).
// Works on a copy, so the original order is not changed.
void show_sorted(Student *list, int size) {
    if (size == 0) {
        printf("No students stored; nothing to sort.\n");
        return;
    }
    Student *copy = create_student_list(size);
    if (copy == NULL) {
        printf("Error: not enough memory to sort.\n");
        return;
    }
    for (int i = 0; i < size; i++) copy[i] = list[i];

    for (int i = 0; i < size - 1; i++) {          // bubble sort
        for (int j = 0; j < size - 1 - i; j++) {
            int swap = 0;
            if (copy[j].gpa < copy[j + 1].gpa) swap = 1;
            else if (copy[j].gpa == copy[j + 1].gpa && copy[j].roll > copy[j + 1].roll) swap = 1;
            if (swap) {
                Student temp = copy[j];
                copy[j] = copy[j + 1];
                copy[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by GPA (highest first):\n");
    display_students(copy, size);
    free_student_list(copy);
}

void print_menu() {
    printf("\n===== Student Records System =====\n");
    printf("1. Add student\n");
    printf("2. Display all students\n");
    printf("3. Search by roll number\n");
    printf("4. Update student\n");
    printf("5. Delete student\n");
    printf("6. GPA summary (highest / lowest / average)\n");
    printf("7. Display sorted by GPA\n");
    printf("0. Exit\n");
}

// Original fixed demo from the first version of this program.
int run_demo() {
    int number_of_students = 3;
    Student *student_list = create_student_list(number_of_students);
    if (student_list == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    add_student(student_list, 0, 1, "Aladdin", 20, 3.5);
    add_student(student_list, 1, 2, "Batman", 21, 3.7);
    add_student(student_list, 2, 3, "Catwoman", 22, 3.8);
    display_students(student_list, number_of_students);
    free_student_list(student_list);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--demo") == 0) return run_demo();

    Student *student_list = NULL;
    int size = 0;           // records stored
    int capacity = 0;       // records allocated

    // Ask for the initial capacity until it works.
    while (student_list == NULL) {
        char buf[LINE_SIZE];
        int n;
        if (read_line("Initial capacity (number of students): ", buf, LINE_SIZE) == 0) {
            printf("\nNo input; exiting.\n");
            return 0;
        }
        if (!parse_int(buf, &n)) {
            printf("Error: please enter a whole number.\n");
        } else if (n <= 0) {
            printf("Error: capacity must be at least 1.\n");
        } else if (n > MAX_CAPACITY) {
            printf("Error: capacity too large (maximum %d).\n", MAX_CAPACITY);
        } else {
            student_list = create_student_list(n);
            if (student_list == NULL) {
                printf("Error: could not allocate memory for %d students. Try a smaller number.\n", n);
            } else {
                capacity = n;
                printf("Allocated space for %d students.\n", capacity);
            }
        }
    }

    int choice = -1;
    while (choice != 0) {
        char buf[LINE_SIZE];
        print_menu();
        if (read_line("Choice: ", buf, LINE_SIZE) == 0) {   // end of input
            printf("\n");
            break;
        }
        if (!parse_int(buf, &choice)) {
            printf("Error: enter a number from the menu.\n");
            choice = -1;
            continue;
        }

        if (choice == 1) add_new_student(&student_list, &size, &capacity);
        else if (choice == 2) {
            if (size == 0) printf("No students stored.\n");
            else display_students(student_list, size);
        }
        else if (choice == 3) search_student(student_list, size);
        else if (choice == 4) update_student(student_list, size);
        else if (choice == 5) remove_student(student_list, &size);
        else if (choice == 6) show_summary(student_list, size);
        else if (choice == 7) show_sorted(student_list, size);
        else if (choice != 0) printf("Error: invalid menu choice.\n");
    }

    free_student_list(student_list);
    printf("Memory released. Goodbye.\n");
    return 0;
}

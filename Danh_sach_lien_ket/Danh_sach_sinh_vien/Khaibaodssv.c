typedef struct
{
    char ID[10];
    char Name[50];
    float R1, R2, R3;
} Student;

struct Node
{
    Student Element;
    struct Node *Next;
};

typedef struct Node *Position;
typedef Position List;
#include<stdio.h>
#include<string.h>

struct student {
    char name[40];
    int r;
    float m;
};

struct temp {
    char name[40];
    int r;
    float m;
};

// Function to calculate the length of a string
int mystrlen(char str[]) {
    int c = 0, i = 0;
    while (str[i] != '\0') {
        c++;
        i++;
    }
    return c;
}

// Function to compare two strings
int mystrcmp(char str1[], char str2[]) {
    int i;
    for (i = 0; str1[i]; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    if ((str1[i] == '\0') && (str2[i] == '\0')) {
        return 0;
    }
}

// Function to scan student data
void scanstruct(struct student *p) {
    printf("Student name? : ");
    scanf(" %[^\n]", p->name);
    getchar();
    printf("Roll no: ");
    scanf("%d", &p->r);
    printf("Enter marks: ");
    scanf("%f", &p->m);
}

// Function to sort students based on roll number in ascending order
void sortstudentrollasc(struct student p[], int ne) {
    struct temp st;
    for (int i = 0; i < ne - 1; i++) {
        for (int j = i + 1; j < ne; j++) {
            if ((p[i].r) > (p[j].r)) {
                strcpy(st.name, p[i].name);
                st.r = p[i].r;
                st.m = p[i].m;

                strcpy(p[i].name, p[j].name);
                p[i].r = p[j].r;
                p[i].m = p[j].m;

                strcpy(p[j].name, st.name);
                p[j].r = st.r;
                p[j].m = st.m;
            }
        }
    }
}

// Function to sort students based on roll number in descending order
void sortstudentrolldsc(struct student p[], int ne) {
    struct temp st;
    for (int i = 0; i < ne - 1; i++) {
        for (int j = i + 1; j < ne; j++) {
            if ((p[i].r) < (p[j].r)) {
                strcpy(st.name, p[i].name);
                st.r = p[i].r;
                st.m = p[i].m;

                strcpy(p[i].name, p[j].name);
                p[i].r = p[j].r;
                p[i].m = p[j].m;

                strcpy(p[j].name, st.name);
                p[j].r = st.r;
                p[j].m = st.m;
            }
        }
    }
}

void sortstudentmarksasc(struct student p[],int ne){
	struct temp st;
	for(int i=0; i<ne-1; i++){
		for(int j=i+1; j<ne; j++){
			if((p[i].m)>(p[j].m)){
				strcpy(st.name,p[i].name);	
				st.r=p[i].r;
				st.m=p[i].m;
				
				strcpy(p[i].name,p[j].name);
				p[i].r=p[j].r;
				p[i].m=p[j].m;

				strcpy(p[j].name,st.name);
				p[j].r=st.r;
				p[j].m=st.m;	

			}

		}
	
	}

}


void sortstudentmarksdsc(struct student p[],int ne){
	struct temp st;
	for(int i=0; i<ne-1; i++){
		for(int j=i+1; j<ne; j++){
			if((p[i].m)>(p[j].m)){
				strcpy(st.name,p[i].name);	
				st.r=p[i].r;
				st.m=p[i].m;
				
				strcpy(p[i].name,p[j].name);
				p[i].r=p[j].r;
				p[i].m=p[j].m;

				strcpy(p[j].name,st.name);
				p[j].r=st.r;
				p[j].m=st.m;	

			}

		}
	
	}

}



// Function to delete student by name
void deletestudentbyname(struct student s[], int *ne) {
    char nam[40];
    printf("Enter the student name to delete: ");
    scanf(" %[^\n]", nam);
    getchar();
    
    for (int i = 0; i < *ne; i++) {
        int c = mystrcmp(s[i].name, nam);
        if (c == 0) {
            for (int j = i; j < *ne - 1; j++) {
                strcpy(s[j].name, s[j + 1].name);
                s[j].r = s[j + 1].r;
                s[j].m = s[j + 1].m;
            }
            *ne = *ne - 1;
            printf("\n");
            printf("Student '%s' deleted successfully!\n", nam);
            printf("\n");
            return;
        }
    }
    printf("Student '%s' not found!\n", nam);
}

// Function to print student details
void printstruct(struct student *p) {
    printf("Name: %s\nRoll no.: %d\nMarks: %.2f\n", p->name, p->r, p->m);
}

void main() {
    int ne, op;
    printf("Enter the number of students: ");
    scanf("%d", &ne);

    struct student s[ne];

    for (int i = 0; i < ne; i++) {
        scanstruct(&s[i]);
        printf("\n");
    }

    printf("\n**\n");

    while (1) {
        printf("Enter 1 to sort student data(ascend)\n");
        printf("Enter 2 to sort student data(desecnd)\n");
        printf("Enter 3 to delete student by name\n");
        printf("Enter 4 to sort student data by marks(asc)\n");
        printf("Enter 5 to sort student data by marks(dsc)\n");
        printf("Enter 6 to print student list\n");
        printf("Enter 7 to exit\n");
        printf("\n");
        printf("Enter the number to perform operation: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                sortstudentrollasc(s, ne);
                printf("\n");
                printf("Students sorted by roll number (ascending).\n");
                printf("\n");
                break;
            case 2:
                sortstudentrolldsc(s, ne);
                printf("\n");
                printf("Students sorted by roll number (ascending).\n");
                printf("\n");
                break;    
            case 3:
                deletestudentbyname(s, &ne);
                break;
            case 4:
                sortstudentmarksasc(s, ne);
                printf("\n");
                printf("Students sorted by roll number (ascending).\n");
                printf("\n");
                break;
            case 5:
                sortstudentmarksdsc(s, ne);
                printf("\n");
                printf("Students sorted by roll number (ascending).\n");
                printf("\n");
                break;    
            case 6:
                for (int i = 0; i < ne; i++) {
                    printstruct(&s[i]);
                    printf("\n");
                }
                break;
            case 7:
                return;
            default:
            printf("\n");
                printf("Invalid option!\n");
                printf("\n");
        }
    }
}

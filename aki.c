#include <stdio.h>
#include <stdbool.h>

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

typedef enum {
    A, B, C, D, E, F,
    NUM_OF_REGISTERS
} Registers;

int registers[NUM_OF_REGISTERS];

bool running = true;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

int ip = 0;
int sp = -1;
int stack[256];

int fetch();
void eval(int instr);

int main() {
    while (running) {
        eval(fetch());
        ip++;
    }
    return 0;
}

int fetch() {
    return program[ip];
}

void eval(int instr) {
    switch (instr) {
        case PSH: {
            sp++;
            stack[sp] = program[++ip];
            break;
        }
        case POP: {
            int val_popped = stack[sp--];
            printf("popped %d\n", val_popped);
            break;
        }
        case ADD: {
             int a = stack[sp--];
             int b = stack[sp--];

             int result = b + a;
             sp++;
             stack[sp] = result;
             break;
        }
        case HLT: {
            running = false;
            break;
        }
    }
    return;  
}

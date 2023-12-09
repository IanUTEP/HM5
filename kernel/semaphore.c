#include "types.h"
#include "riscv.h"
#include "param.h"
#include "defs.h"
#include "spinlock.h"
struct semtab semtable;
void
seminit(void)
{
initlock(&semtable.lock, "semtable");
for (int i = 0; i < NSEM; i++)
initlock(&semtable.sem[i].lock, "sem");
};
int
semalloc(int j){ //J isn't used too lazy to change
for (int i =0; i < NSEM; i++){
acquire(&semtable.sem[i].lock);
   if(&semtable.sem[i].valid){
   release(&semtable.sem[i].lock);
   return i;
	}
release(&semtable.sem[i].lock);
}
return -1;
};
void
semdealloc(int j){
acquire(&semtable.sem[j].lock);
semtable.sem[j].valid = 0;
release(&semtable.sem[j].lock);
printf("Test");
};
//seminit(), semalloc() and
//semdealloc()

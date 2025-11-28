#ifndef CALLBACKS_H
#define CALLBACKS_H

typedef void (*ActionInt)(int);

void for_positive(int from, int to, ActionInt act);

#endif /* CALLBACKS_H */
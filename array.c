/*TODO
array.h:
    depends on size_t, perror? abort?
    size or length:   sizeof a->v / sizeof *a->v
    DefineTypeArray(T,N) // Type must be an identifier
    DefineTypeArrayName(T,N,Name) Type may be anything
    .at
    .atsafe: check abort one liner
    Print, AreEqual? -> memcmp, copy: no need.
    Test.c
    Example.c
Why?
    pointer
    return
    copy with assignment
    pass
How: Wraps around.
Inspiration array
*/

#include<assert.h>

#define DefineTypeArray(T,N) typedef struct{T at[N];} Array_##T##_##N

DefineTypeArray(int,5);

Array_int_5 Add( const Array_int_5*, const Array_int_5*);

int main(void){
    Array_int_5 a={{0,1,2,3,4}}, b={{0,10,20,30,40}}, c = Add(&a, &b);
    assert(c.at[0]==0 );
    assert(c.at[1]==11);
    assert(c.at[2]==22);
    assert(c.at[3]==33);
    assert(c.at[4]==44);
    c = b;
    assert(c.at[0]==0 );
    assert(c.at[1]==10);
    assert(c.at[2]==20);
    assert(c.at[3]==30);
    assert(c.at[4]==40);
}

#include<stdlib.h> // size_t

Array_int_5 Add(const Array_int_5 *a, const Array_int_5 *b){
    Array_int_5 c;
    for(size_t i=0; i < sizeof a->at / sizeof *a->at; ++i)
        c.at[i] = a->at[i] + b->at[i];
    return c;
}


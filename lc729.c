typedef struct {
    int p[1000][2];
    int n;
} MyCalendar;

MyCalendar* myCalendarCreate() {
    MyCalendar* M = (MyCalendar*)malloc(sizeof(MyCalendar));
    M->n = 0;
    return M;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    int i;
    for (i = 0;i < obj->n;i++)
    {
        if ( !(start >= (obj->p)[i][1] || end <= (obj->p)[i][0])){
            return false;
        }
    }
    (obj->p)[i][0] = start;
    (obj->p)[i][1] = end;
    obj->n++;
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    //free(obj->p);
    free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * struct MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 * myCalendarFree(obj);
 */

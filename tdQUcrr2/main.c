#include <stdio.h>
#include "queue.h"

// Initialize the queue
void initializeQueue(Queue *q) {
    q->rear = 0;  // Set the rear marker to 0 (empty queue)
}

// Check if the queue is empty
int is_empty(Queue *q) {
    return q->rear == 0;  // If rear is 0, the queue is empty
}

// Check if the queue is full
int is_full(Queue *q) {
    return q->rear == MAX_SIZE;  // If rear has reached MAX_SIZE, the queue is full
}

// Enqueue an element
void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }
    q->queue[q->rear] = value;
    q->rear++;  // Move rear marker to the next position
}

// Dequeue an element
int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }

    int value = q->queue[0];  // Get the first element (front of the queue)

    // Shift all elements one position to the left
    for (int i = 0; i < q->rear - 1; i++) {
        q->queue[i] = q->queue[i + 1];
    }

    q->rear--;  // Decrement rear since we've removed one element
    return value;
}

// Peek at the front element
int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot peek\n");
        return -1;
    }/*الكود المقدم هو تعريف وتنفيذ عمليات على "طابور" (Queue) باستخدام لغة البرمجة C. إليك شرح كل جزء من الكود بالعربية:

1. تضمين المكتبات:

#include <stdio.h>: هذه المكتبة تستخدم للطباعة على الشاشة ولإجراء العمليات المدخلة من المستخدم مثل printf و scanf.

#include "queue.h": هذه المكتبة هي عبارة عن تعريفات إضافية تخص هيكلية الطابور (Queue) قد تكون موجودة في ملف آخر يحتوي على تعريف الهيكلية (Structure) و الثوابت المرتبطة بها مثل الحجم الأقصى للطابور.



2. تهيئة الطابور:

void initializeQueue(Queue *q) {
    q->rear = 0;  // Set the rear marker to 0 (empty queue)
}

هذه الدالة تقوم بتهيئة الطابور عن طريق تعيين مؤشر (rear) إلى القيمة 0، مما يعني أن الطابور فارغ في البداية.


3. التحقق إذا كان الطابور فارغًا:

int is_empty(Queue *q) {
    return q->rear == 0;  // If rear is 0, the queue is empty
}

هذه الدالة تقوم بالتحقق إذا كان الطابور فارغًا أم لا، وذلك بالتحقق إذا كان مؤشر  (rear) يساوي 0. إذا كان كذلك، فهذا يعني أن الطابور فارغ.


4. التحقق إذا كان الطابور ممتلئًا:

int is_full(Queue *q) {
    return q->rear == MAX_SIZE;  // If rear has reached MAX_SIZE, the queue is full
}

هذه الدالة تتحقق إذا كان الطابور قد امتلأ أم لا. إذا كان مؤشر  (rear) قد وصل إلى القيمة القصوى للطابور (MAX_SIZE)، فهذا يعني أن الطابور ممتلئ.


5. إضافة عنصر إلى الطابور (إدخال):

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }
    q->queue[q->rear] = value;
    q->rear++;  // Move rear marker to the next position
}

هذه الدالة تضيف عنصرًا إلى الطابور. قبل إضافة العنصر، تتحقق إذا كان الطابور ممتلئًا باستخدام دالة is_full. إذا كان الطابور ممتلئًا، يتم طباعة رسالة تحذير. إذا لم يكن ممتلئًا، يتم إدخال العنصر في المكان المناسب وتحديث مؤشر  (rear) لزيادة القيمة وبالتالي الانتقال إلى المكان التالي.


6. إزالة عنصر من الطابور (إخراج):

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }

    int value = q->queue[0];  // Get the first element (front of the queue)

    // Shift all elements one position to the left
    for (int i = 0; i < q->rear - 1; i++) {
        q->queue[i] = q->queue[i + 1];
    }

    q->rear--;  // Decrement rear since we've removed one element
    return value;
}

هذه الدالة تقوم بإزالة العنصر الأول من الطابور. إذا كان الطابور فارغًا، سيتم طباعة رسالة تحذير. إذا لم يكن فارغًا، يتم استخراج العنصر الأول وتخزينه في متغير value. ثم يتم تحريك جميع العناصر الأخرى في الطابور إلى اليسار لتغطية مكان العنصر الذي تم إخراجه. وفي النهاية، يتم تقليل مؤشر  (rear) لأنه تم إزالة عنصر.


7. معاينة العنصر الأول في الطابور (دون إخراجه):

int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot peek\n");
        return -1;
    }
    return q->queue[0];  // The first element is always at index 0
}

هذه الدالة تسمح بمعاينة العنصر الأول في الطابور دون إخراجه. إذا كان الطابور فارغًا، سيتم طباعة رسالة تحذير. وإذا لم يكن فارغًا، يتم إرجاع العنصر الأول الذي يوجد في المكان الأول في الطابور (الذي يكون في الفهرس 0).



خلاصة:

الكود يقوم بتعريف طابور مع مجموعة من العمليات الأساسية مثل التهيئة، التحقق من حالة الطابور (فارغ أو ممتلئ)، إضافة العناصر، إزالة العناصر، ومعاينة العنصر الأول. يتم استخدام هذه العمليات لتخزين البيانات في هيكل بيانات الطابور بطريقة منظمة.*/
    return q->queue[0];  // The first element is always at index 0
}

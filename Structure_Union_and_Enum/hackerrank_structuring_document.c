#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

typedef struct document Document;
typedef struct paragraph Paragraph;
typedef struct sentence Sentence;
typedef struct word Word;

unsigned short paragraph_cnt = 0;
unsigned short sentence_cnt = 0;
unsigned short word_cnt = 0;

Word* get_words(char *sentence)
{
    word_cnt = 0;
    Word* structured_words = NULL;
    char* token = strtok(sentence, " ");
    char **words = NULL;

    while (token)
    {
        words = (char**)realloc(words, (word_cnt + 1) * sizeof(char*));
        words[word_cnt] = token;
        ++word_cnt;
        token = strtok(NULL, " ");
    }
    
    structured_words = (Word*)malloc( word_cnt * sizeof(Word) );

    for (int i = 0; i < word_cnt; i++)
    {
        structured_words[i].data = words[i];
    }
    
    free(words);
    return structured_words;

}

Sentence* get_sentences(char *paragraph)
{
    Sentence* structured_sentences = NULL;
    sentence_cnt = 0;
    char** sentences = NULL;
    char* token = strtok(paragraph, ".");

    while (token)
    {
        sentences = (char**)realloc(sentences, (sentence_cnt + 1) * (sizeof(char*)) );
        sentences[sentence_cnt] = token;
        ++sentence_cnt;
        token = strtok(NULL, ".");
    }

    structured_sentences = (Sentence*)malloc(sentence_cnt * sizeof(Sentence));

    for (int i = 0; i < sentence_cnt; i++)
    {
        structured_sentences[i].data = get_words(sentences[i]);
        structured_sentences[i].word_count = word_cnt; 
    }

    free(sentences);
    return structured_sentences;
     
}

Paragraph* get_paragraphs(char* document)
{   
    Paragraph* structured_paragraph = NULL;
    char* paragraphs[MAX_PARAGRAPHS];
    char* token = strtok(document, "\n");

    while (token)
    {
        paragraphs[paragraph_cnt] = token;
        ++paragraph_cnt;
        token = strtok(NULL, "\n");
    }

    structured_paragraph = (Paragraph*)malloc(paragraph_cnt * sizeof(Paragraph));

    for (int i = 0; i < paragraph_cnt; i++)
    {
        structured_paragraph[i].data = get_sentences(paragraphs[i]);
        structured_paragraph[i].sentence_count = sentence_cnt;
    }

    return structured_paragraph;
}


struct document get_document(char* text) {

    Document* document = (Document*)malloc(sizeof(Document));
    document->data = get_paragraphs(text);
    document->paragraph_count = paragraph_cnt;
    return *document;      
    
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
        return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
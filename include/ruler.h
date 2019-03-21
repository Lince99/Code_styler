/*
 * Copyright (c) 2019 Lince99
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/*
 * RULER:
 * read the xml file with all rules used by a specified language,
 * then convert it into an xml tree structure,
 * and finally gets all rules.
 * Than ruler have access to these rules and permit to you to modify it
 * (with examples), or you can provide some code snippets to read from.
 */

#ifndef RULER_H
#define RULER_H

#include <stdio.h>
#include <stdlib.h>

//signatures
typedef struct XMLTREE_T xmlTree_t;
typedef struct XMLNODE_T xmlNode_t;
typedef struct XMLATTR_T xmlAttr_t;

struct XMLTREE_T {
    char* tree_name; /* aka read file name */
    char* content; /* if not NULL, it contains the copy of the .xml file */
    xmlNode_t* root; /* first root structure tag */
};

struct XMLNODE_T {
    int is_comment; /* flag that if is equal to 1 this node is a comment */
    /* <tag attributes.attr="attributes.attr_val"> tag_value </tag> */
    char* tag; /* the extracted tag name */
    xmlNodeAttr_t* attribute; /* list of attributes of the node */
    xmlNode_t* child; /* list of child nodes */
    xmlNode_t* next; /* next node (aka brother of this node)*/
};

struct XMLNODE_ATTR_T {
    char* attr; /* attribute name inside tag */
    char* attr_val; /* attribute value associated with attr */
    xmlNodeAttr_t* next; /* next attribute (aka brother of this attrbute)*/
};



/*
 * function that initialize one xmlTree_t structure
 */
xmlTree_t* init_xmlTree(void) {
    xmlTree_t* node = NULL;

    node = (xmlTree_t*) malloc(sizeof(xmlTree_t));
    if(node == NULL) {
        perror("Failed to alloc xmlTree_t!\n");
        return NULL;
    }
    node->tree_name = NULL;
    node->content = NULL;
    node->root = NULL;

    return node;
}

/*
 * function that initialize one xmlTree_t structure
 */
xmlNode_t* init_xmlNode(void) {
    xmlNode_t* node = NULL;

    node = (xmlNode_t*) malloc(sizeof(xmlNode_t));
    if(node == NULL) {
        perror("Failed to alloc xmlNode_t!\n");
        return NULL;
    }
    node->is_comment = 0;
    node->tag = NULL;
    node->attribute = NULL;
    node->child = NULL;
    node->next = NULL;

    return node;
}

/*
 * function that initialize one xmlNodeAttr_t structure
 */
xmlNodeAttr_t* init_xmlNodeAttr(void) {
    xmlNodeAttr_t* node = NULL;

    node = (xmlNodeAttr_t*) malloc(sizeof(xmlNodeAttr_t));
    if(node == NULL) {
        perror("Failed to alloc xmlNodeAttr_t!\n");
        return NULL;
    }
    node->attr = NULL;
    node->attr_val = NULL;
    node->next = NULL;

    return node;
}

/*
 * print the xml proprieties and its tree structure with colors and indentation
 */
void print_doc(xmlTree_t* doc) {
    char* data = NULL;
    int data_len = 0;
    int trace = 0;

    if(doc == NULL) {
        printf(ANSI_YELLOW "Void document!" ANSI_RESET "\n");
        return;
    }
    printf("Xml name = " ANSI_CYAN "\""%s\"" ANSI_RESET "\n", doc->tree_name);
    //print colorized xml
    data = doc->content;
    data_len = strlen(data);
    /*
     * 0 = BLUE = tag
     * 1 = CYAN = tag_value
     * 2 = RED = attribute
     * 3 = MAGENTA == attribute_value
     * 4 = GREEN = comment
     * 5 = YELLOW = close tag
     * WHITE = uknown
     */
    for(; i < data_len; i++) {
        //open tag
        if(data[i] == '<' || (trace == 3 && data[i] == '>'))
            trace = 0;
        //comment
        if(data[i+1] == '!' && trace == 0)
            trace = 4;
        //attribute
        if(data[i] == ' ' && (trace == 0 || trace == 3))
            trace = 2;
        //attribute value
        if(data[i] == '=' && trace == 2)
            trace = 3;
        //close tag
        if(data[i-1] == '>')
            trace = 1;
        //stampa
        switch(trace) {
            case 0:
                printf(ANSI_BLUE);
                break;
            case 1:
                printf(ANSI_CYAN);
                break;
            case 2:
                printf(ANSI_RED);
                break;
            case 3:
                printf(ANSI_MAGENTA);
                break;
            case 4:
                printf(ANSI_GREEN);
                break;
            default:
                printf(ANSI_WHITE);
                break;
        }
        printf("%c", data[i]);
    }
    printf(ANSI_RESET "\n");
    //check if there is some tree saved
    printf("Tree structrure is: ");
    if(doc->root != NULL)
        printf(ANSI_CYAN "SAVED" ANSI_RESET "\n");
    else
        printf(ANSI_YELLOW "NOT SAVED" ANSI_RESET "\n");

}

/*
 * procedure that print one node, its attributes and its childs
 */
void print_node(xmlNode* node) {
    int i = 0;

    if(node == NULL) {
        printf(ANSI_YELLOW "Void node!" ANSI_RESET "\n");
        return;
    }
    //TODO

    
}



#endif //RULER_H

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
 * library that provide various functions that elaborate strings
 */

#ifndef STRING_MANAGER_H
#define STRING_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//signatures
int get_pos(char* data, int start, char find);
char* substring(char* str, int start, int end);
char* trim_string(char* str);
char* trim_xml(char* str);



/*
 * function that search the position of "find" char
 * in the string "data" starting at "start" position.
 * It returns -1 in case of errors,
 * else a positive number bigger that start is returned
 */
int get_pos(char* data, int start, char find) {
    int lung = 0;

    if(data == NULL)
        return -1;
    lung = (int) strlen(data);
    if(start >= lung)
        return -1;
    for(; start < lung; start++) {
        if(data[start] == find)
            return start;
    }

    return -1;
}

/*
 * function that return the extracted string from "str" at start to end
 */
char* substring(char* str, int start, int end) {
    char* new_s = NULL;
    int str_len = (int) strlen(str);
    int i = 0;

    if(start > end || str == NULL ||
       start == end || end > str_len)
        return NULL;
    if(start == 0 && end == str_len)
        return str;
    new_s = (char*) malloc(sizeof(char)*(end-start+1));
    while(start < end) {
        new_s[i] = str[start];
        ++start;
        ++i;
    }
    new_s[i] = '\0';

    return new_s;
}

/*
 * remove tabs, spaces, newlines and other indentation chars
 * from the head and from the tail of "str"
 */
char* trim_string(char* str) {
    int i = 0;
    int start = 0;
    int end = (int) strlen(str);

    if(str == NULL)
        return NULL;
    //remove head indentation
    for(; i < (int) strlen(str); i++) {
        if(str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
            ++start;
        else
            break;
    }
    //remove tail indentation
    for(i = (int) strlen(str)-1; i > start; i--) {
        if(str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
            --end;
        else
            break;
    }
    str = substring(str, start, end);

    return str;
}

/*
 * remove all spaces, tabs and newline from xml tags
 */
char* trim_xml(char* str) {
    int i = 0;
    int j = 0;
    int out_tag = 0;
    int save = 1;
    char* copy = NULL;

    if(str == NULL || strlen(str) == 0)
        return NULL;
    copy = (char*) calloc(sizeof(char), strlen(str));
    for(i = 0; i < (int) strlen(str); i++) {
        //if it's out of tag then search for indentation spaces
        if(str[i] == '>')
            out_tag = 1;
        //else save all characters inside tags
        if(str[i] == '<')
            out_tag = 0;
        //if it's out and it finds tag values, it saves these
        if(out_tag) {
            if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
                save = 0;
            else
                save = 1;
        }
        //apply last controls
        if(!out_tag || save) {
            copy[j] = str[i];
            j++;
        }
    }
    copy = (char*) realloc(copy, sizeof(char)*(j+1));
    copy[j] = '\0';

    return copy;
}

#endif //STRING_MANAGER_H

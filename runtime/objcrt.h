#ifndef RT_H_
#define RT_H_

#include <runtime/code-api.h>


typedef struct {
    int count;  // number of pointer pairs that follow
    void *modStart;
    void *modEnd;
    void *protoStart;
    void *protoEnd;
    void *iiStart;
    void *iiEnd;
    void *selrefsStart;
    void *selrefsEnd;
    void *clsrefsStart;
    void *clsrefsEnd;
} code_sections;

CODE_EXPORT void *_code_init_image(HMODULE image, const code_sections *sects);
CODE_EXPORT void _code_load_image(HMODULE image, void *hinfo);
CODE_EXPORT void _code_unload_image(HMODULE image, void *hinfo);

#endif

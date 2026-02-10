#include <stdio.h>

int main() {
    int n, key;
    
    // Read size of array
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read element to search
    scanf("%d", &key);
    
    // Linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("found at position %d\n", i);
            return 0;
        }
    }
    
    // If element not found
    printf("%d not found\n", key);
    
    return 0;
}


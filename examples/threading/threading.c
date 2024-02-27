/*Refering Lecture notes: 
    Implementation by Jyotin Jose
*/
#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{

    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    thread_func_args->thread_complete_success = false;
    
    if(thread_func_args == NULL)
    {
        ERROR_LOG("thread_data is invalid\n");
        return thread_param;
    }
    usleep(thread_func_args->wait_to_obtain*1000);
    // if(pthread_mutex_init(thread_func_args->mMutex, NULL)!=0) //Initialize
    // {
    //     ERROR_LOG("Mutex initialization failed!!!\n");
    //     return thread_param;
    // }
    if(pthread_mutex_lock(thread_func_args->mMutex)!= 0)  //Obtain mutex lock
    {
        ERROR_LOG("Mutex Locking failed!!!\n");
        return thread_param; 
    }
    
    usleep(thread_func_args->wait_to_release_ms*1000);

    if(pthread_mutex_unlock(thread_func_args->mMutex) != 0)
    {
        ERROR_LOG("Mutex unlocking failed!!!\n");
        return NULL; 
    }

    thread_func_args->thread_complete_success = true;

    return thread_param;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{      
    struct thread_data *thread_data_obj = (struct thread_data*)malloc(sizeof(struct thread_data));  //DYnamic memory allocation
    if(thread_data_obj == NULL)
    {
        ERROR_LOG("FAiled to allocate memory");
        return false;
    }
    thread_data_obj->mMutex = mutex;
    thread_data_obj->wait_to_obtain = wait_to_obtain_ms;
    thread_data_obj->wait_to_release_ms = wait_to_release_ms;
    thread_data_obj->thread_complete_success = false;

    int rc = pthread_create(thread, NULL, threadfunc, (void*)thread_data_obj);
    if(rc != 0)
    {
        ERROR_LOG("Error: Failed to create thread!\n");
        free(thread_data_obj);
        return false;
    }

    // if(pthread_join(thread, NULL) != 0)
    // {
    //     ERROR_LOG("Error: attempting to join the thread! \n");
    //     free(thread);
    //     return false;
    // }

    if(thread_data_obj->thread_complete_success)
    {
        printf("MUtex locked\n");
        DEBUG_LOG("Mutex lock ");
        printf("MUtex unlocked\n");
    }
    
    
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */

    return true;
}


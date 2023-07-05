/****************************************************************************************
* ALI SAHBAZ
*
*
* ASZ Framework
*
* Date          : 05.07.2023
* By            : Ali Þahbaz
* e-mail        : ali_sahbaz@outlook.com
*/

#include "subject_api.h"

subject_func_out_types 
subject_create(subject_obj* me, SBJ_DATA* subject_data)
{
	if (me == NULL) {
		return SUBJECT_FUNC_FAIL;
	}

	me->data = subject_data;

	int i = 0;

	for (i = 0; i < SUBJECT_S_MAX_OBSERVER_COUNT; i++) {
		me->observers[i] = NULL;
	}

	me->_is_created = 1;

	me->observer_count = 0;

	return SUBJECT_FUNC_SUCCESS;
}

subject_func_out_types 
subject_add_observer(subject_obj* me, observer_obj* observer)
{
	if (me == NULL || observer == NULL || !me->_is_created || me->observer_count > (SUBJECT_S_MAX_OBSERVER_COUNT-2)) { /** todo; can 2->1 ? **/
		return SUBJECT_FUNC_FAIL;
	}

    me->observers[me->observer_count] = observer;

#ifdef OBSERVER_SPACIAL_OBJECT_NOTIFYS_ACTIVE
	/** first call for notify load success **/
	observer_update(me->observers[me->observer_count], OBSERVER_EVENT_SUBJECT_ADDED, *me->data);
#endif	  

	me->observer_count++;

	return SUBJECT_FUNC_SUCCESS; 
}

subject_func_out_types 
subject_remove_observer(subject_obj* me, observer_obj* observer)
{
	if (me == NULL || observer == NULL || !me->_is_created   ) {
		return SUBJECT_FUNC_FAIL;
	}
	 
	int i = 0 , _is_delete_success = 0;

	for (i = 0; i < SUBJECT_S_MAX_OBSERVER_COUNT; i++) {
		if (_is_delete_success && i > 0) {
			if (me->observers[i] == NULL) { 
				break; 
			}

			/** slide observers array **/
			me->observers[i - 1] = me->observers[i];
			me->observers[i] = NULL;
		}
		else if (me->observers[i] == observer) {

#ifdef OBSERVER_SPACIAL_OBJECT_NOTIFYS_ACTIVE
			/** first call for notify load success **/
			observer_update(me->observers[i], OBSERVER_EVENT_SUBJECT_DELETED, *me->data);
#endif	

			me->observers[i] = NULL;

			me->observer_count--;

			_is_delete_success = 1; 
		}
	}
	 
	if (_is_delete_success) {
		return SUBJECT_FUNC_SUCCESS;
	}

	/** observer not found **/
	return SUBJECT_FUNC_FAIL;
}




subject_func_out_types 
subject_update_observers(subject_obj* me)
{
	if (me == NULL || !me->_is_created ) {
		return SUBJECT_FUNC_FAIL;
	}
	 
	int i = 0;

	for (i = 0; i < me->observer_count; i++) {
		if (me->observers[i]) {
			observer_update(me->observers[i], OBSERVER_EVENT_UPDATE, *me->data);
		}
	}
	  
	return SUBJECT_FUNC_SUCCESS;
}


subject_func_out_types
subject_delete(subject_obj* me)
{
	if (me == NULL) {
		return SUBJECT_FUNC_FAIL;
	}

	me->data = NULL;

	int i = 0;

	for (i = 0; i < SUBJECT_S_MAX_OBSERVER_COUNT; i++) {
		me->observers[i] = NULL;
	}

	me->_is_created = 0;

	me->observer_count = 0;

	return SUBJECT_FUNC_SUCCESS;
}
// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from navigation_interfaces:srv/Path.idl
// generated code does not contain a copyright notice
#include "navigation_interfaces/srv/detail/path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
navigation_interfaces__srv__Path_Request__init(navigation_interfaces__srv__Path_Request * msg)
{
  if (!msg) {
    return false;
  }
  // positions
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positions, 0)) {
    navigation_interfaces__srv__Path_Request__fini(msg);
    return false;
  }
  return true;
}

void
navigation_interfaces__srv__Path_Request__fini(navigation_interfaces__srv__Path_Request * msg)
{
  if (!msg) {
    return;
  }
  // positions
  rosidl_runtime_c__double__Sequence__fini(&msg->positions);
}

bool
navigation_interfaces__srv__Path_Request__are_equal(const navigation_interfaces__srv__Path_Request * lhs, const navigation_interfaces__srv__Path_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // positions
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positions), &(rhs->positions)))
  {
    return false;
  }
  return true;
}

bool
navigation_interfaces__srv__Path_Request__copy(
  const navigation_interfaces__srv__Path_Request * input,
  navigation_interfaces__srv__Path_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // positions
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positions), &(output->positions)))
  {
    return false;
  }
  return true;
}

navigation_interfaces__srv__Path_Request *
navigation_interfaces__srv__Path_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Path_Request * msg = (navigation_interfaces__srv__Path_Request *)allocator.allocate(sizeof(navigation_interfaces__srv__Path_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navigation_interfaces__srv__Path_Request));
  bool success = navigation_interfaces__srv__Path_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navigation_interfaces__srv__Path_Request__destroy(navigation_interfaces__srv__Path_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navigation_interfaces__srv__Path_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navigation_interfaces__srv__Path_Request__Sequence__init(navigation_interfaces__srv__Path_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Path_Request * data = NULL;

  if (size) {
    data = (navigation_interfaces__srv__Path_Request *)allocator.zero_allocate(size, sizeof(navigation_interfaces__srv__Path_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navigation_interfaces__srv__Path_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navigation_interfaces__srv__Path_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
navigation_interfaces__srv__Path_Request__Sequence__fini(navigation_interfaces__srv__Path_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      navigation_interfaces__srv__Path_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

navigation_interfaces__srv__Path_Request__Sequence *
navigation_interfaces__srv__Path_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Path_Request__Sequence * array = (navigation_interfaces__srv__Path_Request__Sequence *)allocator.allocate(sizeof(navigation_interfaces__srv__Path_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navigation_interfaces__srv__Path_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navigation_interfaces__srv__Path_Request__Sequence__destroy(navigation_interfaces__srv__Path_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navigation_interfaces__srv__Path_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navigation_interfaces__srv__Path_Request__Sequence__are_equal(const navigation_interfaces__srv__Path_Request__Sequence * lhs, const navigation_interfaces__srv__Path_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navigation_interfaces__srv__Path_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navigation_interfaces__srv__Path_Request__Sequence__copy(
  const navigation_interfaces__srv__Path_Request__Sequence * input,
  navigation_interfaces__srv__Path_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navigation_interfaces__srv__Path_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    navigation_interfaces__srv__Path_Request * data =
      (navigation_interfaces__srv__Path_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navigation_interfaces__srv__Path_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          navigation_interfaces__srv__Path_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navigation_interfaces__srv__Path_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
navigation_interfaces__srv__Path_Response__init(navigation_interfaces__srv__Path_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
navigation_interfaces__srv__Path_Response__fini(navigation_interfaces__srv__Path_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
navigation_interfaces__srv__Path_Response__are_equal(const navigation_interfaces__srv__Path_Response * lhs, const navigation_interfaces__srv__Path_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
navigation_interfaces__srv__Path_Response__copy(
  const navigation_interfaces__srv__Path_Response * input,
  navigation_interfaces__srv__Path_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

navigation_interfaces__srv__Path_Response *
navigation_interfaces__srv__Path_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Path_Response * msg = (navigation_interfaces__srv__Path_Response *)allocator.allocate(sizeof(navigation_interfaces__srv__Path_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navigation_interfaces__srv__Path_Response));
  bool success = navigation_interfaces__srv__Path_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navigation_interfaces__srv__Path_Response__destroy(navigation_interfaces__srv__Path_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navigation_interfaces__srv__Path_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navigation_interfaces__srv__Path_Response__Sequence__init(navigation_interfaces__srv__Path_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Path_Response * data = NULL;

  if (size) {
    data = (navigation_interfaces__srv__Path_Response *)allocator.zero_allocate(size, sizeof(navigation_interfaces__srv__Path_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navigation_interfaces__srv__Path_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navigation_interfaces__srv__Path_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
navigation_interfaces__srv__Path_Response__Sequence__fini(navigation_interfaces__srv__Path_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      navigation_interfaces__srv__Path_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

navigation_interfaces__srv__Path_Response__Sequence *
navigation_interfaces__srv__Path_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Path_Response__Sequence * array = (navigation_interfaces__srv__Path_Response__Sequence *)allocator.allocate(sizeof(navigation_interfaces__srv__Path_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navigation_interfaces__srv__Path_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navigation_interfaces__srv__Path_Response__Sequence__destroy(navigation_interfaces__srv__Path_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navigation_interfaces__srv__Path_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navigation_interfaces__srv__Path_Response__Sequence__are_equal(const navigation_interfaces__srv__Path_Response__Sequence * lhs, const navigation_interfaces__srv__Path_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navigation_interfaces__srv__Path_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navigation_interfaces__srv__Path_Response__Sequence__copy(
  const navigation_interfaces__srv__Path_Response__Sequence * input,
  navigation_interfaces__srv__Path_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navigation_interfaces__srv__Path_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    navigation_interfaces__srv__Path_Response * data =
      (navigation_interfaces__srv__Path_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navigation_interfaces__srv__Path_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          navigation_interfaces__srv__Path_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navigation_interfaces__srv__Path_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

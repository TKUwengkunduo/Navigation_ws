// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from navigation_interfaces:srv/PathService.idl
// generated code does not contain a copyright notice
#include "navigation_interfaces/srv/detail/path_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `paths`
#include "rosidl_runtime_c/string_functions.h"

bool
navigation_interfaces__srv__PathService_Request__init(navigation_interfaces__srv__PathService_Request * msg)
{
  if (!msg) {
    return false;
  }
  // paths
  if (!rosidl_runtime_c__String__init(&msg->paths)) {
    navigation_interfaces__srv__PathService_Request__fini(msg);
    return false;
  }
  return true;
}

void
navigation_interfaces__srv__PathService_Request__fini(navigation_interfaces__srv__PathService_Request * msg)
{
  if (!msg) {
    return;
  }
  // paths
  rosidl_runtime_c__String__fini(&msg->paths);
}

bool
navigation_interfaces__srv__PathService_Request__are_equal(const navigation_interfaces__srv__PathService_Request * lhs, const navigation_interfaces__srv__PathService_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // paths
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->paths), &(rhs->paths)))
  {
    return false;
  }
  return true;
}

bool
navigation_interfaces__srv__PathService_Request__copy(
  const navigation_interfaces__srv__PathService_Request * input,
  navigation_interfaces__srv__PathService_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // paths
  if (!rosidl_runtime_c__String__copy(
      &(input->paths), &(output->paths)))
  {
    return false;
  }
  return true;
}

navigation_interfaces__srv__PathService_Request *
navigation_interfaces__srv__PathService_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__PathService_Request * msg = (navigation_interfaces__srv__PathService_Request *)allocator.allocate(sizeof(navigation_interfaces__srv__PathService_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navigation_interfaces__srv__PathService_Request));
  bool success = navigation_interfaces__srv__PathService_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navigation_interfaces__srv__PathService_Request__destroy(navigation_interfaces__srv__PathService_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navigation_interfaces__srv__PathService_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navigation_interfaces__srv__PathService_Request__Sequence__init(navigation_interfaces__srv__PathService_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__PathService_Request * data = NULL;

  if (size) {
    data = (navigation_interfaces__srv__PathService_Request *)allocator.zero_allocate(size, sizeof(navigation_interfaces__srv__PathService_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navigation_interfaces__srv__PathService_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navigation_interfaces__srv__PathService_Request__fini(&data[i - 1]);
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
navigation_interfaces__srv__PathService_Request__Sequence__fini(navigation_interfaces__srv__PathService_Request__Sequence * array)
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
      navigation_interfaces__srv__PathService_Request__fini(&array->data[i]);
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

navigation_interfaces__srv__PathService_Request__Sequence *
navigation_interfaces__srv__PathService_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__PathService_Request__Sequence * array = (navigation_interfaces__srv__PathService_Request__Sequence *)allocator.allocate(sizeof(navigation_interfaces__srv__PathService_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navigation_interfaces__srv__PathService_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navigation_interfaces__srv__PathService_Request__Sequence__destroy(navigation_interfaces__srv__PathService_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navigation_interfaces__srv__PathService_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navigation_interfaces__srv__PathService_Request__Sequence__are_equal(const navigation_interfaces__srv__PathService_Request__Sequence * lhs, const navigation_interfaces__srv__PathService_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navigation_interfaces__srv__PathService_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navigation_interfaces__srv__PathService_Request__Sequence__copy(
  const navigation_interfaces__srv__PathService_Request__Sequence * input,
  navigation_interfaces__srv__PathService_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navigation_interfaces__srv__PathService_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    navigation_interfaces__srv__PathService_Request * data =
      (navigation_interfaces__srv__PathService_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navigation_interfaces__srv__PathService_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          navigation_interfaces__srv__PathService_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navigation_interfaces__srv__PathService_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `confirmation`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
navigation_interfaces__srv__PathService_Response__init(navigation_interfaces__srv__PathService_Response * msg)
{
  if (!msg) {
    return false;
  }
  // confirmation
  if (!rosidl_runtime_c__String__init(&msg->confirmation)) {
    navigation_interfaces__srv__PathService_Response__fini(msg);
    return false;
  }
  return true;
}

void
navigation_interfaces__srv__PathService_Response__fini(navigation_interfaces__srv__PathService_Response * msg)
{
  if (!msg) {
    return;
  }
  // confirmation
  rosidl_runtime_c__String__fini(&msg->confirmation);
}

bool
navigation_interfaces__srv__PathService_Response__are_equal(const navigation_interfaces__srv__PathService_Response * lhs, const navigation_interfaces__srv__PathService_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // confirmation
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->confirmation), &(rhs->confirmation)))
  {
    return false;
  }
  return true;
}

bool
navigation_interfaces__srv__PathService_Response__copy(
  const navigation_interfaces__srv__PathService_Response * input,
  navigation_interfaces__srv__PathService_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // confirmation
  if (!rosidl_runtime_c__String__copy(
      &(input->confirmation), &(output->confirmation)))
  {
    return false;
  }
  return true;
}

navigation_interfaces__srv__PathService_Response *
navigation_interfaces__srv__PathService_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__PathService_Response * msg = (navigation_interfaces__srv__PathService_Response *)allocator.allocate(sizeof(navigation_interfaces__srv__PathService_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navigation_interfaces__srv__PathService_Response));
  bool success = navigation_interfaces__srv__PathService_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navigation_interfaces__srv__PathService_Response__destroy(navigation_interfaces__srv__PathService_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navigation_interfaces__srv__PathService_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navigation_interfaces__srv__PathService_Response__Sequence__init(navigation_interfaces__srv__PathService_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__PathService_Response * data = NULL;

  if (size) {
    data = (navigation_interfaces__srv__PathService_Response *)allocator.zero_allocate(size, sizeof(navigation_interfaces__srv__PathService_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navigation_interfaces__srv__PathService_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navigation_interfaces__srv__PathService_Response__fini(&data[i - 1]);
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
navigation_interfaces__srv__PathService_Response__Sequence__fini(navigation_interfaces__srv__PathService_Response__Sequence * array)
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
      navigation_interfaces__srv__PathService_Response__fini(&array->data[i]);
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

navigation_interfaces__srv__PathService_Response__Sequence *
navigation_interfaces__srv__PathService_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__PathService_Response__Sequence * array = (navigation_interfaces__srv__PathService_Response__Sequence *)allocator.allocate(sizeof(navigation_interfaces__srv__PathService_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navigation_interfaces__srv__PathService_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navigation_interfaces__srv__PathService_Response__Sequence__destroy(navigation_interfaces__srv__PathService_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navigation_interfaces__srv__PathService_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navigation_interfaces__srv__PathService_Response__Sequence__are_equal(const navigation_interfaces__srv__PathService_Response__Sequence * lhs, const navigation_interfaces__srv__PathService_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navigation_interfaces__srv__PathService_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navigation_interfaces__srv__PathService_Response__Sequence__copy(
  const navigation_interfaces__srv__PathService_Response__Sequence * input,
  navigation_interfaces__srv__PathService_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navigation_interfaces__srv__PathService_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    navigation_interfaces__srv__PathService_Response * data =
      (navigation_interfaces__srv__PathService_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navigation_interfaces__srv__PathService_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          navigation_interfaces__srv__PathService_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navigation_interfaces__srv__PathService_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

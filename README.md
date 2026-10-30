# Sequencer Software Pack

![tag](https://img.shields.io/badge/tag-2.1.2-brightgreen.svg)
[![release note](https://img.shields.io/badge/release_note-view_html-gold.svg)](https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-util-sequencer/blob/main/Release_Notes.html)

## Overview

The Sequencer is a utility that helps schedule tasks in systems without an OS.

## Description and Usage

### Description:

The Sequencer utility has been designed as a simple alternative to using a real-time operating system for less complex application cases. However, it does not cover all the services provided by an operating system.

The main features of Sequencer are:

- Task creation: Register a task so the Sequencer can call it.
- Task enable: Mark a task runnable from another task or an interrupt.
- Task pause/resume: Temporarily stop or resume a task from the scheduler’s viewpoint.
- Idle task: Optional hook called when no task is runnable.

### Usage:

The start-up sequence can be split into five steps:

### Step 1: Sequencer initialization

Initialize the Sequencer once with `SEQ_Init()` after basic hardware setup and before scheduling any tasks

### Step 2: Task Definitions

Define tasks as short non-preemptive functions that return quickly, using either single-action tasks (one-shot actions) or state-machine tasks (advance one step per call with internal state).

### Step 3: Registering Tasks

Register each task with a task ID bit and its callback function using `SEQ_RegTask()`.

### Step 4: Enabling Task Execution

To schedule work, set the task bit with a priority index (0 = highest) using `SEQ_SetTask()`.

### Step 5: Launching the Sequencer

Call `SEQ_Run()` inside the infinite loop to let the Sequencer process all pending tasks.
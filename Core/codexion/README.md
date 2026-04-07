*This project has been created as part of the 42 curriculum by [aben-cad](https://profile-v3.intra.42.fr/users/aben-cad).*

# Codexion

## Description
Codexion is a high-performance multithreading simulation in C that models a collaborative coding environment. The objective is to efficiently allocate shared constraints (limited compilation dongles) among multiple distinct tasks (Coders) without triggering deadlocks or starvation resulting in coder "burnout".

## Instructions
Codexion complies perfectly with C89 standard norms and uses POSIX threads. 

To compile the executable:
```bash
make
```

### Ready-to-Test Example
Once compiled, you can immediately test the simulation with this survivable configuration:
```bash
./codexion 4 800 200 200 200 5 10 fifo
```
This runs 4 coders, giving them 800ms before burnout, with 200ms for each action (compile, debug, refactor), requiring 5 compiles each, a 10ms dongle cooldown, using the `fifo` scheduler.

### Manual Usage
To run the simulation with custom parameters:
```bash
./codexion number_of_coders time_to_burnout time_to_compile time_to_debug time_to_refactor number_of_compiles_required dongle_cooldown scheduler
```
*Note: The `scheduler` must be either `fifo` or `edf`.*

---

## Blocking cases handled
Because multiple coders share localized hardware (Right & Left Dongles instances), they are highly susceptible to deadlocks. The following cases were natively handled:
- **Starvation and Cooldown Pauses**: A `pthread_cond_broadcast` signal dynamically pulses within a separate tracking thread (`monitor.c`) every millisecond to gracefully wake up any queued threads instantly awaiting dongle `cooldown_times`.
- **Deadlock Multi-mutex locks**: All threading events are guarded by custom Mutex conditions (`arbitrator_mutex`), avoiding circular holding patterns by only granting locks when exactly 2 dongles simultaneously declare an unlocked and "cooled-down" state.
- **Log Serialization Interleaving**: Custom `printf` wrappers are strictly serialized via a generic global `print_mutex` protecting logs against mid-string overlapping or racing to output dead states.

## Thread synchronization mechanisms
This simulation operates completely on mutual exclusion primitives (`pthread_mutex_t`) tied heavily into a dynamic Priority Queue (`pthread_cond_t`):
- **pthread_mutex_t**: Each array piece of hardware (`t_dongle`) corresponds equivalently to an individual mutex representing hardware lock states against arbitrary use. State evaluations are purely synchronized via standard locking techniques locking any thread's ability to update `last_compile_starts`.
- **pthread_cond_wait / broadcast**: Instead of raw arbitrary spin-locking, execution handles CPU limits by pushing Coder threads safely to suspend (`pthread_cond_wait`). The scheduler strictly evaluates `POLICY_FIFO` integer limits (`wants_to_compile`) or `POLICY_EDF` epoch ties, manually granting single passes. The main monitoring thread handles the condition broadcasts (`pthread_cond_broadcast`) notifying all asleep candidates safely. 

## Resources
This project utilizes logic similar to standard Operating System CPU scheduling queues alongside Dijkstra's classical "Dining Philosophers Problem".
- **AI Integration**: AI (Gemini) was utilized to construct the baseline queue architecture algorithms distinguishing `Earliest Deadline First` (EDF) from `First In, First Out` (FIFO) sorting models, while simultaneously pinpointing Posix thread-locking syntax deadlocks.

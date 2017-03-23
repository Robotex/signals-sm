# Signals for SourceMod

## About
The purpose of this extension is to allow Source servers (tested on Left 4 Dead 2) to handle signals, useful in the cases where the server is run in a containerized environment such as Docker.
At the current state, the extension will intercept all SIGTERM signals if there are players and will shutdown the server only when everyone has left.
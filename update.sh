while [[ 1 ]]; do inotifywait -e modify content/*; make; done

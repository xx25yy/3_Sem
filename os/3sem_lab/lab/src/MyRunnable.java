class MyRunnable implements Runnable {
    private volatile boolean running = true;

    @Override
    @SuppressWarnings("deprecation")
    public void run() {
        while (running) {
            try {
                Thread.sleep(500);
                System.out.println("Thread ID: " + Thread.currentThread().getId() + " is running.");
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted.");
            }
        }
    }

    public void stopThread() {
        running = false;
    }
}

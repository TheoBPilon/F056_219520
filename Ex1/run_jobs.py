import multiprocessing as mp
import subprocess # para chamar o executavel

def run_job(n):
    with open(f"output_{n}.txt","w") as f:
        subprocess.run([f"./hello",str(n)], stdout = f)

if __name__ == "__main__":
    MAX_WORKERS = max(mp.cpu_count()-1,1) # peha o nproc
    pool = mp.Pool(MAX_WORKERS) # cria o conjunto de proc trrabalhadores
    pool.map(run_job,range(1,11))

